#ifndef PLAYLISTITEMTESTPANEL_H
#define PLAYLISTITEMTESTPANEL_H

//(*Headers(PlayListItemTestPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/choice.h>
//*)

class PlayListItemTest;

class PlayListItemTestPanel: public wxPanel
{
    PlayListItemTest* _test;
    void ValidateWindow();
    void SetChoiceFromString(wxChoice* choice, std::string value);

	public:

		PlayListItemTestPanel(wxWindow* parent, PlayListItemTest* test, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PlayListItemTestPanel();

		//(*Declarations(PlayListItemTestPanel)
		wxTextCtrl* TextCtrl_Name;
		wxSpinCtrl* SpinCtrl_Channels;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxChoice* Choice_Mode;
		wxSpinCtrl* SpinCtrl_Value1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl_FrameDuration;
		wxSpinCtrl* SpinCtrl_Value2;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl_Duration;
		wxStaticText* StaticText4;
		wxSpinCtrl* SpinCtrl_StartChannel;
		//*)

	protected:

		//(*Identifiers(PlayListItemTestPanel)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT6;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL3;
		//*)

	private:

		//(*Handlers(PlayListItemTestPanel)
		void OnTextCtrl_NameText(wxCommandEvent& event);
		void OnChoice_ModeSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
