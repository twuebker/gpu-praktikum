#ifndef ForceFieldDialog_h
#define ForceFieldDialog_h

#include <QDialog>
#include <QtWidgets>
#include "../ui/ui_ForceFieldDialog.h"

class CreateForceFieldDialog : public Ui::ForceFieldDialog, public QDialog
{
public:
	CreateForceFieldDialog();
public slots:
	void accept();
	void reject();
public:
	int getWidth();
	int getHeight();
	int getForce();
	int getDirection();
};
#endif
