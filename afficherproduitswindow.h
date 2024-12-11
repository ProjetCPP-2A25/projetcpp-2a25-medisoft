/*#ifndef AFFICHERPRODUITSWINDOW_H
#define AFFICHERPRODUITSWINDOW_H

#include <QTableWidget>
#include <QWidget>
#include "LesProduits .h"

class AfficherProduitsWindow : public QWidget {
    Q_OBJECT

public:
    explicit AfficherProduitsWindow(LesProduits* produits, QWidget* parent = nullptr);

private:
    QTableWidget* tableProduits;  // Tableau pour afficher les produits
    LesProduits* lesProduits;    // Référence aux produits à afficher
    void setupTable();           // Configuration du tableau
    void remplirTable();         // Remplir les données dans le tableau
};

#endif // AFFICHERPRODUITSWINDOW_H
*/
