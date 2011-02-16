/*
 * Xournal Extended
 *
 * Handles input and optimizes the stroke
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <gtk/gtk.h>
#include "../../model/Stroke.h"
#include "../../model/Page.h"
#include "../../gui/Redrawable.h"
#include "../../util/Util.h"

class DocumentView;
class XournalWidget;

class InputHandler : public MemoryCheckObject {
public:
	InputHandler(XournalWidget * xournal, GtkWidget * widget, Redrawable * redrawable);
	virtual ~InputHandler();

public:
	void addPointToTmpStroke(GdkEventMotion * event);
	void draw(cairo_t * cr);
	void onButtonReleaseEvent(GdkEventButton * event, XojPage * page);
	bool onMotionNotifyEvent(GdkEventMotion * event);
	void startStroke(GdkEventButton * event, StrokeTool tool, double x, double y);

	Stroke * getTmpStroke();

private:
	bool getPressureMultiplier(GdkEvent * event, double & presure);
	void drawTmpStroke();

private:
	XournalWidget * xournal;

	/**
	 * If you are drawing on the document
	 */
	Stroke * tmpStroke;

	/**
	 * What has already be drawed, only draw the new part
	 */
	int tmpStrokeDrawElem;

	/**
	 * The current input device for stroken, do not react on other devices (linke mices)
	 */
	GdkDevice * currentInputDevice;

	/**
	 * The view widget for drawing
	 */
	GtkWidget * widget;

	/**
	 * The View to draw the stroke
	 */
	DocumentView * view;

	/**
	 * The view which should be refreshed
	 */
	Redrawable * redrawable;
};

#endif /* __INPUTHANDLER_H__ */