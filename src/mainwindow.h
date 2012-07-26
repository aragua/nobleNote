#ifndef NOBLENOTE_H
#define NOBLENOTE_H

#include "ui_mainwindow.h"
#include <QSyntaxHighlighter>
#include <QSystemTrayIcon>
#include <QSplitter>
#include <QFileSystemModel>
#include <QListView>
#include <QAbstractItemModel>
#include <QToolButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPointer>


/**
 * @brief note taking application main window
 *
 *  nb short for notebook
 *  n short for note
 *  f short for folder
 */

//#define NO_SYSTEM_TRAY_ICON

class Welcome;
class Preferences;
class FindFileModel;
class FindFileSystemModel;
class FileSystemModel;
class LineEdit;
class Note;
class Highlighter;

class NobleNote : public QMainWindow, public Ui::NobleNote {
     Q_OBJECT // important for creating own singals and slots
 
     public:
      NobleNote();
      ~NobleNote();


public slots:
    void quit();
private:
      Welcome         *welcome;
      QSplitter       *splitter;
      LineEdit        *searchName, *searchText;
      FileSystemModel *folderModel;
      FileSystemModel *noteFSModel;
      FindFileSystemModel * noteModel;
      QListView       *folderList;
      QListView         *noteList;
      QAction         *quit_action;
      QIcon           icon;
      Preferences     *pref;
      QAction         *minimize_restore_action;
      QHBoxLayout     *hBoxLayout;
      FindFileModel   *findNoteModel;
      QList<QPointer<Note> >     openNotes; // every access to openNotes must check for null pointers
      Highlighter *highlighter;

#ifndef NO_SYSTEM_TRAY_ICON
      QMenu           *iMenu;
      QSystemTrayIcon *TIcon;
#endif

      Note * noteWindow(const QString & filePath); // return the open note window for the note at filePath

     private slots:
      void changeRootIndex();
      void setCurrentFolder(const QModelIndex &ind);

#ifndef NO_SYSTEM_TRAY_ICON
      void iconActivated(QSystemTrayIcon::ActivationReason reason);
      void tray_actions();
#endif

      void find();
      void openNote(const QModelIndex &ind = QModelIndex());
      void showContextMenuF(const QPoint &pos);
      void showContextMenuN(const QPoint &pos);
      void newFolder();
      void newNote();
      void renameFolder();
      void renameNote();
      void removeFolder();
      void removeNote();
      void importXmlNotes();
      void selectFirstFolder(QString path); // select first folder
      void folderRenameFinished( QWidget * editor, QAbstractItemDelegate::EndEditHint hint = QAbstractItemDelegate::NoHint ); // reloads current folder
      void noteRenameFinished(const QString &path, const QString &oldName, const QString &newName); // updates window title
      void about();

     protected:
      void keyPressEvent(QKeyEvent *k);
      virtual void closeEvent(QCloseEvent* window_close);
      virtual void showEvent(QShowEvent* window_show);
      virtual void hideEvent(QHideEvent* window_hide);
};

#endif
