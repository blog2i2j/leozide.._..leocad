#pragma once

#include "minifig.h"

class lcColorPicker;
class lcDoubleSpinBox;

namespace Ui
{
class lcMinifigDialog;
}

class lcMinifigDialog : public QDialog
{
	Q_OBJECT

public:
	explicit lcMinifigDialog(QWidget* Parent);
	~lcMinifigDialog();

	MinifigWizard* mMinifigWizard;

protected slots:
	void on_TemplateComboBox_currentIndexChanged(const QString& TemplateName);
	void on_TemplateSaveButton_clicked();
	void on_TemplateDeleteButton_clicked();
	void on_TemplateImportButton_clicked();
	void on_TemplateExportButton_clicked();
	void PieceButtonClicked();
	void ColorChanged(int Index);
	void AngleChanged(double Value);

protected:
	void UpdateTemplateCombo();
	void SetCurrentTemplateModified();

	Ui::lcMinifigDialog* ui;

	lcView* mView;
	std::array<QToolButton*, LC_MFW_NUMITEMS> mPieceButtons;
	std::array<lcColorPicker*, LC_MFW_NUMITEMS> mColorPickers;
	std::array<lcDoubleSpinBox*, LC_MFW_NUMITEMS> mSpinBoxes;

	QString mCurrentTemplateName;
	bool mCurrentTemplateModified = false;
};
