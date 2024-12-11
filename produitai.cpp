#include "produitai.h"
#include <QDebug>
#include <QString>

/*ProduitAI::ProduitAI(const QString& code, const QString& type)
    : code(code), type(type) {
    // Si le constructeur a d'autres initialisations, vérifiez aussi ici
}*/
ProduitAI::ProduitAI(const QString &code, const QString &type)
{
    this->code = code;
    this->tab = type.split(",");
    this->nbr = 0; // Initialiser à 0
}

void ProduitAI::setCode(const QString &newCode)
{
    this->code = newCode; // Assigner la nouvelle valeur au code
}

QStringList ProduitAI::getTab() const
{
    return tab; // Retourne le tableau des types
}

void ProduitAI::setOUI(ProduitAI *oui)
{
    OUI = oui; // Assigne le fils droit
}

void ProduitAI::setNON(ProduitAI *non)
{
    NON = non; // Assigne le fils gauche
}

QString ProduitAI::getCode() const
{
    return code; // Retourne le code du produit
}

QString ProduitAI::getType() const
{
    return type; // Retourne le type du produit
}

ProduitAI *ProduitAI::getOUI() const
{
    return OUI; // Retourne le pointeur vers l'enfant droit (OUI)
}

ProduitAI *ProduitAI::getNON() const
{
    return NON; // Retourne le pointeur vers l'enfant gauche (NON)
}

/*void ProduitAI::remplirTab() {
    // On commence par vider le tableau (au cas où il contient déjà des données)
    tab.clear();

    // Le type est une chaîne séparée par des virgules (par exemple : "A,B,C")
    QStringList typeList = type.split(',');

    // Remplir le tableau avec les éléments de la liste
    for (const QString& item : typeList) {
        tab.append(item);  // Ajouter chaque élément dans le tableau 'tab'
    }
}*/

/*void ProduitAI::remplirTab() {
    // Exemple de remplissage du tableau 'tab' basé sur l'attribut 'type'
    tab = type.split(",");  // Sépare la chaîne 'type' par les virgules et remplit le tableau
}

void ProduitAI::supprimerArbre() {
    // Supprimer récursivement les sous-arbres
    if (OUI) {
        OUI->supprimerArbre();  // Supprimer le sous-arbre droit
        delete OUI;  // Libérer la mémoire du fils droit
        OUI = nullptr;  // Réinitialiser le pointeur
    }

    if (NON) {
        NON->supprimerArbre();  // Supprimer le sous-arbre gauche
        delete NON;  // Libérer la mémoire du fils gauche
        NON = nullptr;  // Réinitialiser le pointeur
    }
}*/

void ProduitAI::afficherArbre(int niveau)
{
    // Afficher le code et le type du produit actuel avec indentation pour visualiser la structure de l'arbre
    QString indentation = QString("  ").repeated(niveau); // Créer l'indentation selon le niveau
    qDebug() << indentation << "Produit : " << "Code:" << code << ", Type:" << type;

    // Afficher le sous-arbre gauche (NON)
    if (NON != nullptr) {
        qDebug() << indentation << "-> NON : ";
        NON->afficherArbre(niveau + 1); // Appel récursif avec un niveau supérieur
    }

    // Afficher le sous-arbre droit (OUI)
    if (OUI != nullptr) {
        qDebug() << indentation << "-> OUI : ";
        OUI->afficherArbre(niveau + 1); // Appel récursif avec un niveau supérieur
    }
}

int ProduitAI::comparerTab(const ProduitAI *autreProduit)
{
    int count = 0;
    // Comparer les types des deux produits
    for (const QString &t1 : this->tab) {
        if (autreProduit->tab.contains(t1)) {
            count++; // Si un type est trouvé dans les deux, on incrémente
        }
    }
    this->nbr = count; // Mettre à jour le nombre de types répétés
    return count;
}

void ProduitAI::afficherProduit() const
{
    qDebug() << "Produit : Code: " << code << ", Types: " << tab.join(",");
}
