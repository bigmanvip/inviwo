#ifndef IVW_TRANSFERFUNCTIONPROPERTYWIDGET_H
#define IVW_TRANSFERFUNCTIONPROPERTYWIDGET_H

#include <inviwo/core/properties/properties.h>
#include <inviwo/qt/widgets/properties/propertywidgetqt.h>
#include <inviwo/qt/widgets/properties/transferfunctionpropertydialog.h>
#include <inviwo/qt/widgets/inviwoapplicationqt.h>
#include <inviwo/qt/widgets/editablelabelqt.h>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGradient>

namespace inviwo {

class IVW_QTWIDGETS_API TransferFunctionPropertyWidgetQt : public PropertyWidgetQt {
	Q_OBJECT

public:
	TransferFunctionPropertyWidgetQt(TransferFunctionProperty* property);
	~TransferFunctionPropertyWidgetQt();

	void updateFromProperty();

private:
    QToolButton* btnOpenTF_;
    EditableLabelQt* label_;
    QLinearGradient* gradient_;
    QGraphicsView* gradientView_; 
    QGraphicsScene* gradientScene_;
    TransferFunctionProperty* property_;

	TransferFunctionPropertyDialog* transferFunctionDialog_;

	void generateWidget();

	public slots:
		void setPropertyValue();
		void openTransferFunctionDialog();
        void setPropertyDisplayName();
};

}//namespace

#endif //IVW_TRANSFERFUNCTIONPROPERTYWIDGET_H