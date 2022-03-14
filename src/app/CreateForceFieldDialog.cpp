#include "CreateForceFieldDialog.h"

CreateForceFieldDialog::CreateForceFieldDialog() {
	setupUi(this);
}

void CreateForceFieldDialog::reject() {
	done(0);
}

void CreateForceFieldDialog::accept() {
	done(1);
}

int CreateForceFieldDialog::getWidth() {
	return this->widthBox->value();
}

int CreateForceFieldDialog::getHeight() {
	return this->heightBox->value();
}

int CreateForceFieldDialog::getForce() {
	return this->forceSlider->value();
}

int CreateForceFieldDialog::getDirection() {
	return this->selection->currentIndex();
}
