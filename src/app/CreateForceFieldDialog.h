#include <QDialog>
#include <QtWidgets>

class CreateForceFieldDialog : public Ui::ForceFieldDialog, public QDialog
{
	Q_OBJECT
public:
	CreateForceFieldDialog();
public slots:
	void accept();
	void reject();
public:
	int getWidth();
	int getHeight();
	int getForce();
};
