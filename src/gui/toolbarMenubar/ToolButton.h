/*
 * Xournal++
 *
 * Part of the customizable toolbars
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __TOOLBUTTON_H__
#define __TOOLBUTTON_H__

#include "AbstractToolItem.h"
#include "../GladeGui.h"

class ToolButton : public AbstractToolItem
{
public:
    ToolButton(ActionHandler* handler, string id, ActionType type, string stock,
               string description, GtkWidget* menuitem = NULL);
    ToolButton(ActionHandler* handler, GladeGui* gui, string id, ActionType type,
               string iconName, string description, GtkWidget* menuitem = NULL);
    ToolButton(ActionHandler* handler, GladeGui* gui, string id, ActionType type,
               ActionGroup group, bool toolToggleOnlyEnable, string iconName,
               string description,
               GtkWidget* menuitem = NULL);

    virtual ~ToolButton();

public:
    void updateDescription(string description);
    virtual string getToolDisplayName();

protected:
    virtual GtkToolItem* newItem();

    virtual GtkWidget* getNewToolIconImpl();

protected:
    GladeGui* gui;

private:
    XOJ_TYPE_ATTRIB;

    string stock;

    string iconName;
    string description;
};
#endif /* __TOOLBUTTON_H__ */
