#include "telefonszam.h"

Telefonszam& Telefonszam::operator=(Telefonszam& _telefonszam) {
	if(_telefonszam.getTelefonszam().lehetETelefonszam()) telefonszam = _telefonszam.telefonszam;
	return *this;
}