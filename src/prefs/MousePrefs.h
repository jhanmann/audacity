/**********************************************************************

  Audacity: A Digital Audio Editor

  MousePrefs.h

**********************************************************************/

#ifndef __AUDACITY_MOUSE_PREFS__
#define __AUDACITY_MOUSE_PREFS__

#include <wx/defs.h>

#include "PrefsPanel.h"

class wxListCtrl;
class ShuttleGui;

#define MOUSE_PREFS_PLUGIN_SYMBOL ComponentInterfaceSymbol{ XO("Mouse") }

class MousePrefs final : public PrefsPanel
{
 public:
   MousePrefs(wxWindow * parent, wxWindowID winid);
   ~MousePrefs();
   ComponentInterfaceSymbol GetSymbol() override;
   wxString GetDescription() override;

   bool Commit() override;
   wxString HelpPageName() override;
   void PopulateOrExchange(ShuttleGui & S) override;

 private:
   void Populate();
   void CreateList();
   void AddItem(wxString const & buttons,
                wxString const & tool,
                wxString const & action,
                wxString const & comment = {});

   wxListCtrl * mList;
};

/// A PrefsPanel::Factory that creates one MousePrefs panel.
extern PrefsPanel::Factory MousePrefsFactory;
#endif
