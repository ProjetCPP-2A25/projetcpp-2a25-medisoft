#ifndef PATIENTS_H
#define PATIENTS_H

namespace Ui {
class PatientWindow;
}

class PatientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatientWindow(QWidget *parent = nullptr);
    ~PatientWindow();

private:
    Ui::PatientWindow *ui;
};

#endif // PATIENTS_H
