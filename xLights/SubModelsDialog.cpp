#include "SubModelsDialog.h"


#include <wx/xml/xml.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>
#include <wx/tokenzr.h>

#include "models/Model.h"

//(*InternalHeaders(SubModelsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/choice.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
//*)

//(*IdInit(SubModelsDialog)
const long SubModelsDialog::ID_STATICTEXT1 = wxNewId();
const long SubModelsDialog::ID_CHOICE3 = wxNewId();
const long SubModelsDialog::ID_BUTTON3 = wxNewId();
const long SubModelsDialog::ID_BUTTON4 = wxNewId();
const long SubModelsDialog::ID_CHECKBOX1 = wxNewId();
const long SubModelsDialog::ID_GRID1 = wxNewId();
const long SubModelsDialog::ID_BUTTON1 = wxNewId();
const long SubModelsDialog::ID_BUTTON2 = wxNewId();
const long SubModelsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SubModelsDialog,wxDialog)
	//(*EventTable(SubModelsDialog)
	//*)
END_EVENT_TABLE()

#include "ModelPreview.h"
#include "DimmingCurve.h"


SubModelsDialog::SubModelsDialog(wxWindow* parent)
{
	//(*Initialize(SubModelsDialog)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer1;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, _("Sub Models"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	SetClientSize(wxSize(417,215));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	FlexGridSizer2->AddGrowableRow(0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableRow(2);
	FlexGridSizer7 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer7->AddGrowableCol(1);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameChoice = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	NameChoice->SetMinSize(wxDLG_UNIT(this,wxSize(100,-1)));
	FlexGridSizer7->Add(NameChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AddButton = new wxButton(this, ID_BUTTON3, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer7->Add(AddButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeleteButton = new wxButton(this, ID_BUTTON4, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer7->Add(DeleteButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	LayoutCheckbox = new wxCheckBox(this, ID_CHECKBOX1, _("Vertical Buffer Layout"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	LayoutCheckbox->SetValue(false);
	FlexGridSizer3->Add(LayoutCheckbox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	NodesGrid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxVSCROLL, _T("ID_GRID1"));
	NodesGrid->CreateGrid(5,1);
	NodesGrid->EnableEditing(true);
	NodesGrid->EnableGridLines(true);
	NodesGrid->SetColLabelSize(18);
	NodesGrid->SetDefaultColSize(150, true);
	NodesGrid->SetColLabelValue(0, _("Node Ranges"));
	NodesGrid->SetRowLabelValue(0, _("Strand   1"));
	NodesGrid->SetDefaultCellFont( NodesGrid->GetFont() );
	NodesGrid->SetDefaultCellTextColour( NodesGrid->GetForegroundColour() );
	FlexGridSizer4->Add(NodesGrid, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	AddRowButton = new wxButton(this, ID_BUTTON1, _("Add Row"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer5->Add(AddRowButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeleteRowButton = new wxButton(this, ID_BUTTON2, _("Delete Row"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer5->Add(DeleteRowButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 0);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
	ModelPreviewPanelLocation = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	ModelPreviewPanelLocation->SetMinSize(wxDLG_UNIT(this,wxSize(100,100)));
	PreviewSizer = new wxFlexGridSizer(1, 1, 0, 0);
	PreviewSizer->AddGrowableCol(0);
	PreviewSizer->AddGrowableRow(0);
	ModelPreviewPanelLocation->SetSizer(PreviewSizer);
	PreviewSizer->Fit(ModelPreviewPanelLocation);
	PreviewSizer->SetSizeHints(ModelPreviewPanelLocation);
	FlexGridSizer2->Add(ModelPreviewPanelLocation, 1, wxALL|wxEXPAND, 2);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 0);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	FlexGridSizer1->Add(StdDialogButtonSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();
	Center();

	Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SubModelsDialog::OnNameChoiceSelect);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SubModelsDialog::OnAddButtonClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SubModelsDialog::OnDeleteButtonClick);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SubModelsDialog::OnLayoutCheckboxClick);
	Connect(ID_GRID1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&SubModelsDialog::OnNodesGridCellSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SubModelsDialog::OnAddRowButtonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SubModelsDialog::OnDeleteRowButtonClick);
	//*)

    Connect(ID_GRID1,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&SubModelsDialog::OnNodesGridCellChange);
    
    modelPreview = new ModelPreview(ModelPreviewPanelLocation);
    modelPreview->SetMinSize(wxSize(150, 150));
    PreviewSizer->Add(modelPreview, 1, wxALL|wxEXPAND, 0);
    PreviewSizer->Fit(ModelPreviewPanelLocation);
    PreviewSizer->SetSizeHints(ModelPreviewPanelLocation);

    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();
    
    NodesGrid->DeleteRows(0, NodesGrid->GetNumberRows());
}

SubModelsDialog::~SubModelsDialog()
{
	//(*Destroy(SubModelsDialog)
	//*)
}

void SubModelsDialog::Setup(Model *m)
{
    NameChoice->Clear();

    model = m;
    wxXmlNode * root = m->GetModelXml();
    wxXmlNode * child = root->GetChildren();
    while (child != nullptr) {
        if (child->GetName() == "subModel") {
            wxString name = child->GetAttribute("name");
            subModels[name].name = name;
            subModels[name].vertical = child->GetAttribute("layout") == "vertical";
            subModels[name].strands.resize(1);
            subModels[name].strands[0] = "";
            int x = 0;
            while (child->HasAttribute(wxString::Format("line%d", x))) {
                if (x >= subModels[name].strands.size()) {
                    subModels[name].strands.resize(x + 1);
                }
                subModels[name].strands[x] = child->GetAttribute(wxString::Format("line%d", x));
                x++;
            }
            NameChoice->Append(name);
        }
        child = child->GetNext();
    }
    if (NameChoice->GetCount() > 0) {
        NameChoice->SetSelection(0);
        Select(NameChoice->GetString(0));
    } else {
        NameChoice->Disable();
        DeleteButton->Disable();
        NodesGrid->Disable();
        LayoutCheckbox->Disable();
        AddRowButton->Disable();
        DeleteRowButton->Disable();
    }
}
void SubModelsDialog::Save()
{
    wxXmlNode * root = model->GetModelXml();
    wxXmlNode * child = root->GetChildren();
    while (child != nullptr) {
        if (child->GetName() == "subModel") {
            wxXmlNode *n = child;
            child = child->GetNext();
            root->RemoveChild(n);
            delete n;
        } else {
            child = child->GetNext();
        }
    }
    for (auto a = subModels.begin(); a != subModels.end(); a++) {
        child = new wxXmlNode(wxXML_ELEMENT_NODE, "subModel");
        child->AddAttribute("name", a->second.name);
        child->AddAttribute("layout", a->second.vertical ? "vertical" : "horizontal");
        for (int x = 0; x < a->second.strands.size(); x++) {
            child->AddAttribute(wxString::Format("line%d", x), a->second.strands[x]);
        }
        root->AddChild(child);
    }
}

void SubModelsDialog::OnAddButtonClick(wxCommandEvent& event)
{
    wxTextEntryDialog dlg(this, "Enter name for sub model");
    wxString name = "";
    int id = wxID_OK;
    while (name == "" && subModels.find(name) == subModels.end() && id == wxID_OK) {
        id = dlg.ShowModal();
        name= dlg.GetValue();
    }
    if (id == wxID_OK) {
        subModels[name].name = name;
        subModels[name].vertical = false;
        subModels[name].strands.clear();
        subModels[name].strands.push_back("");
        NameChoice->Append(name);
        Select(name);
    }
}

void SubModelsDialog::OnDeleteButtonClick(wxCommandEvent& event)
{
    int answer = wxMessageBox("Are you sure you want to delete sub model " + NameChoice->GetStringSelection() + "?",
                              "Delete Model",
                              wxYES_NO, this);
    if (answer == wxYES) {
        subModels.erase(subModels.find(NameChoice->GetStringSelection()));
        NameChoice->Delete(NameChoice->GetSelection());
        if (NameChoice->GetCount() > 0) {
            NameChoice->SetSelection(0);
            Select(NameChoice->GetStringSelection());
        } else {
            NameChoice->Disable();
            DeleteButton->Disable();
            NodesGrid->Disable();
            LayoutCheckbox->Disable();
            AddRowButton->Disable();
            DeleteRowButton->Disable();
        }
    }
}

void SubModelsDialog::OnNameChoiceSelect(wxCommandEvent& event)
{
    Select(event.GetString());
}
void SubModelsDialog::Select(const wxString &name) {
    NameChoice->Enable();
    DeleteButton->Enable();
    NodesGrid->Enable();
    LayoutCheckbox->Enable();
    AddRowButton->Enable();
    DeleteRowButton->Enable(subModels[name].strands.size() > 1);


    NameChoice->SetStringSelection(name);

    LayoutCheckbox->SetValue(subModels[name].vertical);
    NodesGrid->BeginBatch();
    if (NodesGrid->GetNumberRows() > 0) {
        NodesGrid->DeleteRows(0, NodesGrid->GetNumberRows());
    }
    for (int x = 0; x < subModels[name].strands.size(); x++) {
        NodesGrid->AppendRows(1);
        NodesGrid->SetRowLabelValue(x, wxString::Format("Line %d", (x + 1)));
        NodesGrid->SetCellValue(x, 0, subModels[name].strands[x]);
    }
    NodesGrid->EndBatch();
    NodesGrid->GoToCell(0, 0);
    SelectRow(0);
}


void SubModelsDialog::OnNodesGridCellChange(wxGridEvent& event)
{
    int r = event.GetRow();
    subModels[NameChoice->GetStringSelection()].strands[r] = NodesGrid->GetCellValue(r, 0);
    SelectRow(r);
}

void SubModelsDialog::OnNodesGridCellSelect(wxGridEvent& event)
{
    SelectRow(event.GetRow());
}
void SubModelsDialog::SelectRow(int r) {
    wxString v = NodesGrid->GetCellValue(r, 0);
    int nn = model->GetNodeCount();
    xlColor c(xlDARK_GREY);
    if (model->modelDimmingCurve) {
        model->modelDimmingCurve->apply(c);
    }
    for (int node = 0; node < nn; node++) {
        model->SetNodeColor(node, c);
    }

    wxStringTokenizer wtkz(v, ",");
    while (wtkz.HasMoreTokens()) {
        wxString valstr = wtkz.GetNextToken();
        
        int start, end;
        if (valstr.Contains("-")) {
            int idx = valstr.Index('-');
            start = wxAtoi(valstr.Left(idx));
            end = wxAtoi(valstr.Right(valstr.size() - idx - 1));
        } else {
            start = end = wxAtoi(valstr);
        }
        if (start > end) {
            start = end;
        }
        start--;
        end--;
        for (int n = start; n <= end; n++) {
            if (n < model->GetNodeCount()) {
                model->SetNodeColor(n, xlWHITE);
            }
        }
    }
    model->DisplayEffectOnWindow(modelPreview, 2);
}

void SubModelsDialog::OnLayoutCheckboxClick(wxCommandEvent& event)
{
    subModels[NameChoice->GetStringSelection()].vertical = LayoutCheckbox->GetValue();
}

void SubModelsDialog::OnAddRowButtonClick(wxCommandEvent& event)
{
    wxString name = NameChoice->GetStringSelection();
    subModels[name].strands.push_back("");
    DeleteRowButton->Enable();
    Select(name);
}

void SubModelsDialog::OnDeleteRowButtonClick(wxCommandEvent& event)
{
    wxString name = NameChoice->GetStringSelection();
    int row = NodesGrid->GetGridCursorRow();
    int sz = subModels[name].strands.size();
    subModels[name].strands.erase(subModels[name].strands.begin()+row);
    subModels[name].strands.resize(sz - 1);
    Select(name);
    DeleteRowButton->Enable(subModels[name].strands.size() > 1);
}