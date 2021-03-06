///////////////////////////////////////////////////////////////////////////////
// Name:        src/palmos/toplevel.cpp
// Purpose:     implements wxTopLevelWindow for Palm OS
// Author:      William Osborne - minimal working wxPalmOS port
// Modified by: Wlodzimierz ABX Skiba - more than minimal functionality
// Created:     10/13/04
// RCS-ID:      $Id: toplevel.cpp,v 1.12 2005/02/15 07:24:37 ABX Exp $
// Copyright:   (c) William Osborne <wbo@freeshell.org>, Wlodzimierz Skiba
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma implementation "toplevel.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/app.h"
    #include "wx/toplevel.h"
    #include "wx/dialog.h"
    #include "wx/string.h"
    #include "wx/log.h"
    #include "wx/intl.h"
    #include "wx/frame.h"
    #include "wx/containr.h"        // wxSetFocusToChild()
#endif //WX_PRECOMP

#include "wx/module.h"
#include "wx/display.h"

// controls for sending select event
#include "wx/button.h"
#include "wx/checkbox.h"
#include "wx/radiobut.h"
#include "wx/tglbtn.h"
#include "wx/slider.h"
#include "wx/datectrl.h"

// ----------------------------------------------------------------------------
// globals
// ----------------------------------------------------------------------------

// the name of the default wxWidgets class
extern const wxChar *wxCanvasClassName;

// Pointer to the currently active frame for the form event handler.
wxTopLevelWindowPalm* ActiveParentFrame;

// ============================================================================
// wxTopLevelWindowPalm implementation
// ============================================================================

BEGIN_EVENT_TABLE(wxTopLevelWindowPalm, wxTopLevelWindowBase)
    EVT_ACTIVATE(wxTopLevelWindowPalm::OnActivate)
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// wxTopLevelWindowPalm creation
// ----------------------------------------------------------------------------

void wxTopLevelWindowPalm::Init()
{
}

WXDWORD wxTopLevelWindowPalm::PalmGetStyle(long style, WXDWORD *exflags) const
{
    return 0;
}

bool wxTopLevelWindowPalm::Create(wxWindow *parent,
                                  wxWindowID id,
                                  const wxString& title,
                                  const wxPoint& pos,
                                  const wxSize& size,
                                  long style,
                                  const wxString& name)
{
    // this is a check for limitation mentioned before FrameFormHandleEvent() code
    if(wxTopLevelWindows.GetCount()>0)
        return false;

    ActiveParentFrame=NULL;

    wxTopLevelWindows.Append(this);

    if ( parent )
        parent->AddChild(this);

    SetId( id == wxID_ANY ? NewControlId() : id );

    WinConstraintsType constraints;
    memset(&constraints, 0, sizeof(WinConstraintsType));
    // position
    constraints.x_pos = ( pos.x == wxDefaultCoord ) ? winUndefConstraint : pos.x;
    constraints.y_pos = ( pos.y == wxDefaultCoord ) ? winUndefConstraint : pos.y;
    // size
    constraints.x_min = winUndefConstraint;
    constraints.x_max = winMaxConstraint;
    constraints.x_pref = ( size.x == wxDefaultCoord ) ? winUndefConstraint : size.x;
    constraints.y_min = winUndefConstraint;
    constraints.y_max = winMaxConstraint;
    constraints.y_pref = ( size.y == wxDefaultCoord ) ? winUndefConstraint : size.y;

    FrameForm = FrmNewFormWithConstraints(
                    GetId(),
                    title.c_str(),
                    winFlagBackBuffer,
                    &constraints,
                    0,
                    NULL,
                    0,
                    NULL,
                    0
                );

    if(FrameForm==NULL)
        return false;

    FrmSetEventHandler(FrameForm,FrameFormHandleEvent);

    FrmSetActiveForm(FrameForm);

    ActiveParentFrame=this;

    return true;
}

wxTopLevelWindowPalm::~wxTopLevelWindowPalm()
{
}

// ---------------------------------------------------------------------------
// implementation
// ---------------------------------------------------------------------------

WXWINHANDLE wxTopLevelWindowPalm::GetWinHandle() const
{
    FormType *form = GetForm();
    if(form)
        return FrmGetWindowHandle(form);
    return 0;
}

// ----------------------------------------------------------------------------
// wxTopLevelWindowPalm showing
// ----------------------------------------------------------------------------

void wxTopLevelWindowPalm::DoShowWindow(int nShowCmd)
{
}

bool wxTopLevelWindowPalm::Show(bool show)
{
    FrmDrawForm(FrameForm);

    wxPaintEvent event(m_windowId);
    event.SetEventObject(this);
    GetEventHandler()->ProcessEvent(event);

    return true;
}

// ----------------------------------------------------------------------------
// wxTopLevelWindowPalm maximize/minimize
// ----------------------------------------------------------------------------

void wxTopLevelWindowPalm::Maximize(bool maximize)
{
}

bool wxTopLevelWindowPalm::IsMaximized() const
{
    return false;
}

void wxTopLevelWindowPalm::Iconize(bool iconize)
{
}

bool wxTopLevelWindowPalm::IsIconized() const
{
    return false;
}

void wxTopLevelWindowPalm::Restore()
{
}

void wxTopLevelWindowPalm::DoGetSize( int *width, int *height ) const
{
    RectangleType rect;
    FrmGetFormBounds( GetForm() , &rect );
    if(width)
        *width = rect.extent.x;
    if(height)
        *height = rect.extent.y;
}

// ----------------------------------------------------------------------------
// wxTopLevelWindowPalm fullscreen
// ----------------------------------------------------------------------------

bool wxTopLevelWindowPalm::ShowFullScreen(bool show, long style)
{
    return false;
}

// ----------------------------------------------------------------------------
// wxTopLevelWindowPalm misc
// ----------------------------------------------------------------------------

void wxTopLevelWindowPalm::SetIcon(const wxIcon& icon)
{
}

void wxTopLevelWindowPalm::SetIcons(const wxIconBundle& icons)
{
}

bool wxTopLevelWindowPalm::EnableCloseButton(bool enable)
{
    return false;
}

FormType *wxTopLevelWindowPalm::GetForm() const
{
    return FrmGetActiveForm();
}

bool wxTopLevelWindowPalm::SetShape(const wxRegion& region)
{
    return false;
}

// ----------------------------------------------------------------------------
// wxTopLevelWindow native event handling
// ----------------------------------------------------------------------------

bool wxTopLevelWindowPalm::HandleControlSelect(EventType* event)
{
    int id = event->data.ctlSelect.controlID;

    wxWindow* win = FindWindowById(id,this);
    if(win==NULL)
        return false;

#if wxUSE_BUTTON
    wxButton* button = wxDynamicCast(win,wxButton);
    if(button)
        return button->SendClickEvent();
#endif // wxUSE_BUTTON

#if wxUSE_CHECKBOX
    wxCheckBox* checkbox = wxDynamicCast(win,wxCheckBox);
    if(checkbox)
        return checkbox->SendClickEvent();
#endif // wxUSE_CHECKBOX

#if wxUSE_TOGGLEBTN
    wxToggleButton* toggle = wxDynamicCast(win,wxToggleButton);
    if(toggle)
        return toggle->SendClickEvent();
#endif // wxUSE_TOGGLEBTN

#if wxUSE_RADIOBTN
    wxRadioButton* radio = wxDynamicCast(win,wxRadioButton);
    if(radio)
        return radio->SendClickEvent();
#endif // wxUSE_RADIOBTN

#if wxUSE_DATEPICKCTRL
    wxDatePickerCtrl* datepicker = wxDynamicCast(win,wxDatePickerCtrl);
    if(datepicker)
        return datepicker->SendClickEvent();
#endif // wxUSE_DATEPICKCTRL

#if wxUSE_SLIDER
    wxSlider* slider = wxDynamicCast(win,wxSlider);
    if(slider)
        return slider->SendUpdatedEvent();
#endif // wxUSE_SLIDER

    return false;
}

bool wxTopLevelWindowPalm::HandleControlRepeat(EventType* event)
{
    int id = event->data.ctlRepeat.controlID;

    wxWindow* win = FindWindowById(id,this);
    if(win==NULL)
        return false;

#if wxUSE_SLIDER
    wxSlider* slider = wxDynamicCast(win,wxSlider);
    if(slider)
        return slider->SendScrollEvent(event);
#endif // wxUSE_SLIDER

    return false;
}

bool wxTopLevelWindowPalm::HandleSize(EventType* event)
{
    wxSize newSize(event->data.winResized.newBounds.extent.x,
                   event->data.winResized.newBounds.extent.y);
    wxSizeEvent eventWx(newSize,GetId());
    eventWx.SetEventObject(this);
    return GetEventHandler()->ProcessEvent(eventWx);
}

void wxTopLevelWindowPalm::OnActivate(wxActivateEvent& event)
{
}

/* Palm OS Event handler for the window
 *
 * This function *must* be located outside of the wxTopLevelWindow class because
 * the Palm OS API expects a standalone C function as a callback.  You cannot
 * pass a pointer to a member function of a C++ class as a callback because the
 * prototypes don't match.  (A member function has a hidden "this" pointer as
 * its first parameter).
 *
 * This event handler uses a global pointer to the current wxFrame to process
 * the events generated by the Palm OS form API.  I know this is ugly, but right
 * now I can't think of any other way to deal with this problem.  If someone
 * finds a better solution, please let me know.  My email address is
 * wbo@freeshell.org
 */
static Boolean FrameFormHandleEvent(EventType* event)
{
    // frame and tlw point to the same object but they are for convenience
    // of calling proper structure withiout later dynamic typcasting
    wxFrame* frame = wxDynamicCast(ActiveParentFrame,wxFrame);
    wxTopLevelWindowPalm* tlw = ActiveParentFrame;
    Boolean     handled = false;

    switch (event->eType) {
        case ctlSelectEvent:
            handled = tlw->HandleControlSelect(event);
            break;
        case ctlRepeatEvent:
            handled = tlw->HandleControlRepeat(event);
            break;
        case winResizedEvent:
            handled = tlw->HandleSize(event);
            break;
#if wxUSE_MENUS_NATIVE
        case menuOpenEvent:
            handled = frame->HandleMenuOpen();
            break;
        case menuEvent:
            handled = frame->HandleMenuSelect(event);
            break;
#endif
        default:
            break;
    }

    return handled;
}
