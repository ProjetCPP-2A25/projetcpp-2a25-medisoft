#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>
#include <email.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:







    void on_ajouter_clicked();

    void on_refresh_clicked();

    void on_bt_supprimer_clicked();

    void on_modifier_clicked();
    void remplir_combo_idemploye();

    void on_tableViewE_clicked(const QModelIndex &index);




    void on_PDF_clicked();
    void GESTION_EMPLOYE_STATISTIQUE();

    void on_bt_asc_clicked();

    void on_bt_desc_clicked();

    void on_bt_chercher_clicked();

    void on_envoyer_clicked();

    void on_m_log_out_clicked();

    void on_bt_login_clicked();

    void on_oublier_clicked();
    QString generateRandomCode(int length) ;

    void on_done_clicked();

    void on_m_employe_clicked();

    void on_m_commande_clicked();

    void on_g_c_deconnecter_clicked();

    void on_g_c_menu_clicked();

    void on_m_fournisseur_clicked();

private:
    Ui::MainWindow *ui;
     Employee e;
     mailer emailSender;

};

#endif // MAINWINDOW_H
