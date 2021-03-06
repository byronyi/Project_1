#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "painter.h"
#include "pendialog.h"
#include "linedialog.h"
#include "rectdialog.h"
#include "eraserdialog.h"

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QObject>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QString>
#include <QCloseEvent>
#include <QSettings>
#include <QActionGroup>
#include <QColorDialog>
#include <QToolButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void openRecentFile();
    void clearAll();
    bool resize();
    void zoomIn();
    void zoomOut();
    void changeFColor();
    void changeBColor();
    void aboutQt();
    void updateStatusBar();
    void penSettings();
    void lineSettings();
    void rectSettings();
    void eraserSettings();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createRightButtonSettings();
    void setSize(QSize &);
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

    Painter *painter;

    QLabel *locationLabel;
    QLabel *zoomFactorLabel;
    QLabel *frontColorLabel;
    QLabel *backgroundColorLabel;
    QStringList recentFiles;
    QString curFile;
    //about window

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QToolBar *toolBar;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *closeAction;
    QAction *exitAction;

    QAction *zoomInAction;
    QAction *zoomOutAction;

    QAction *aboutAction;
    QAction *aboutQtAction;

    QAction *unDoAction;
    QAction *reDoAction;
    QAction *clearAllAction;
    QAction *resizeAction;

    QAction *changeFColorAction;
    QAction *changeBColorAction;

    QButtonGroup *setPaintTool;
    QToolButton *setPen;
    QToolButton *setLine;
    QToolButton *setEraser;
    QToolButton *setRect;
};

#endif // MAINWINDOW_H
