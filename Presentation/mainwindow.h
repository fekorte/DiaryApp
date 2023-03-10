#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginview.h"
#include "Business/IBusiness.h"
#include "Common/User.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QListWidget>
#include <QPushButton>

/*
 * @author Chachulski, Korte, Mathea
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(Business::IBusiness* b, const QMap<QString, Common::Diary>& myDiaryMap, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;
    void displayEntries();
    void displayFilteredEntries();

private slots:
    void showLoginView();
    void deleteUser();
    void showEntryView();
    void showTravelEntryView();
    void showTrackingView();
    void changeDiary();
    void createDiary();
    void deleteDiary();
    void openEntryView();

private:
    Ui::MainWindow* ui;
    Business::IBusiness* m_business;
    QString m_currentDiary;
    QMap<QString, Common::Diary> m_myDiaryMap;

    QListWidget* pastEntriesListWidget;

    const QList<QString> getDiaryNameList();
    const QString getDisplayType(const Common::Entry& entry);

    QLineEdit* filterInput;
    QPushButton* filterButton;
    QPushButton* trackMoodPushButton;
};

#endif // MAINWINDOW_H
