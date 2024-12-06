#include "ventilateur.h"

Ventilateur::Ventilateur() : ventilateurStatus(false) {}

Ventilateur::~Ventilateur() {}

bool Ventilateur::isVentilateurOn() const
{
    return ventilateurStatus;
}

void Ventilateur::checkVentilateurStatus()
{
    // Ici, vous devez communiquer avec l'Arduino pour vérifier l'état du ventilateur
    // Exemple avec un port série ou tout autre protocole de communication
    // Si l'Arduino indique que le ventilateur est allumé :
    ventilateurStatus = true;
    emit ventilateurOn(); // Signaler que le ventilateur est allumé
    // Sinon, si le ventilateur est éteint :
    // ventilateurStatus = false;
    // emit ventilateurOff();
}

