#pragma once

namespace JSArray {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for gui
	/// </summary>
	public ref class gui : public System::Windows::Forms::Form
	{
	public:
		gui(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~gui()
		{
			if (components)
			{
				delete components;
			}
		}

    private: 
        System::Windows::Forms::ListView^  array_elements_listview;
        System::Windows::Forms::Button^  delete_array_element_btn;
        System::Windows::Forms::Button^  exit_app_btn;
        System::Windows::Forms::Button^  create_array_btn;
        System::Windows::Forms::RichTextBox^  array_element_input;
        System::Windows::Forms::RichTextBox^  created_array_output;
        System::Windows::Forms::Button^  copy_array_btn;
        System::Windows::Forms::Button^  add_array_element_btn;
        System::Windows::Forms::ColumnHeader^  array_element_col_header;
        System::Windows::Forms::ListViewItem^ new_list_view_element;
        System::Windows::Forms::Label^  element_type_lbl;
        System::Windows::Forms::ComboBox^  element_type_comboBox;

        System::Windows::Forms::CheckBox^  wrap_in_single_quotes_checkbox;
        System::Windows::Forms::Button^  clear_created_array_output_btn;
        System::Windows::Forms::Button^  clear_all_btn;
        System::Windows::Forms::CheckBox^  make_array_object_checkbox;

        System::String^ open_quote = "'";
        System::String^ end_quote = "'"; 
        System::String^ open_double_quote = L"\"";
        System::String^ end_double_quote = L"\"";
        System::String^ element_delimeter = L",";
        System::String^ element_input_text = nullptr;
        System::String^ ARRAY_ELEMENT_INPUT_HINT = L"Enter an element...";
        System::String^ CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT =  L"var <array_name> = [\"item1\", \"item2\", ...];";
        System::String^ CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT =  L"var <array_name> = new Array(\"item1\", \"item2\", ...);";
        System::String^ CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT_SINGLE =  L"var <array_name> = ['item1', 'item2', ...];";
        System::String^ CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT_SINGLE =  L"var <array_name> = new Array('item1', 'item2', ...);";
        System::String^ EMPTY_ARRAY_LITERAL = L"var <array_name> = [];";
        System::String^ EMPTY_ARRAY_OBJECT = L"var <array_name> = new Array();";
        System::String^ full_element_string = nullptr;
        System::String^ full_array_string = nullptr;
        // Flag to signal if the element or elements should be wrapped in single or double quotes.
        bool wrap_elements_with_single_quotes = false;
        // Flag to signal if the element being created is a string type element or not.
        bool use_quotation_marks = true;
        // Flag to signal if an empty array should be created or not.
        bool create_empty_array = false;
        // Flag to signal if the array has been created or not.
        bool array_is_created = false;
        // Flag to signal wether or not an array literal or an array object using the constructor should be made.
        bool use_array_object = false;
    private: System::Windows::Forms::PictureBox^  pictureBox1;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(gui::typeid));
            this->array_elements_listview = (gcnew System::Windows::Forms::ListView());
            this->array_element_col_header = (gcnew System::Windows::Forms::ColumnHeader());
            this->delete_array_element_btn = (gcnew System::Windows::Forms::Button());
            this->exit_app_btn = (gcnew System::Windows::Forms::Button());
            this->create_array_btn = (gcnew System::Windows::Forms::Button());
            this->array_element_input = (gcnew System::Windows::Forms::RichTextBox());
            this->created_array_output = (gcnew System::Windows::Forms::RichTextBox());
            this->copy_array_btn = (gcnew System::Windows::Forms::Button());
            this->add_array_element_btn = (gcnew System::Windows::Forms::Button());
            this->element_type_lbl = (gcnew System::Windows::Forms::Label());
            this->element_type_comboBox = (gcnew System::Windows::Forms::ComboBox());
            this->wrap_in_single_quotes_checkbox = (gcnew System::Windows::Forms::CheckBox());
            this->clear_created_array_output_btn = (gcnew System::Windows::Forms::Button());
            this->clear_all_btn = (gcnew System::Windows::Forms::Button());
            this->make_array_object_checkbox = (gcnew System::Windows::Forms::CheckBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // array_elements_listview
            // 
            this->array_elements_listview->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->array_elements_listview->CheckBoxes = true;
            this->array_elements_listview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->array_element_col_header });
            this->array_elements_listview->GridLines = true;
            this->array_elements_listview->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
            this->array_elements_listview->LabelEdit = true;
            this->array_elements_listview->Location = System::Drawing::Point(12,12);
            this->array_elements_listview->Name = L"array_elements_listview";
            this->array_elements_listview->ShowItemToolTips = true;
            this->array_elements_listview->Size = System::Drawing::Size(248,130);
            this->array_elements_listview->TabIndex = 0;
            this->array_elements_listview->UseCompatibleStateImageBehavior = false;
            this->array_elements_listview->View = System::Windows::Forms::View::Details;
            this->array_elements_listview->SelectedIndexChanged += gcnew System::EventHandler(this,&gui::array_elements_listview_SelectedIndexChanged);
            // 
            // array_element_col_header
            // 
            this->array_element_col_header->Text = L"Elements";
            this->array_element_col_header->Width = 248;
            // 
            // delete_array_element_btn
            // 
            this->delete_array_element_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->delete_array_element_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->delete_array_element_btn->Location = System::Drawing::Point(15,207);
            this->delete_array_element_btn->Name = L"delete_array_element_btn";
            this->delete_array_element_btn->Size = System::Drawing::Size(121,26);
            this->delete_array_element_btn->TabIndex = 1;
            this->delete_array_element_btn->Text = L"Delete Elements";
            this->delete_array_element_btn->UseVisualStyleBackColor = false;
            this->delete_array_element_btn->Click += gcnew System::EventHandler(this,&gui::onDeleteElementBtnClick);
            // 
            // exit_app_btn
            // 
            this->exit_app_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->exit_app_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->exit_app_btn->Location = System::Drawing::Point(15,239);
            this->exit_app_btn->Name = L"exit_app_btn";
            this->exit_app_btn->Size = System::Drawing::Size(121,26);
            this->exit_app_btn->TabIndex = 2;
            this->exit_app_btn->Text = L"Exit App";
            this->exit_app_btn->UseVisualStyleBackColor = false;
            this->exit_app_btn->Click += gcnew System::EventHandler(this,&gui::onExitAppBtnClick);
            // 
            // create_array_btn
            // 
            this->create_array_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->create_array_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->create_array_btn->Location = System::Drawing::Point(142,239);
            this->create_array_btn->Name = L"create_array_btn";
            this->create_array_btn->Size = System::Drawing::Size(118,26);
            this->create_array_btn->TabIndex = 3;
            this->create_array_btn->Text = L"Create []";
            this->create_array_btn->UseVisualStyleBackColor = false;
            this->create_array_btn->Click += gcnew System::EventHandler(this,&gui::onCreateArrayBtnClick);
            // 
            // array_element_input
            // 
            this->array_element_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->array_element_input->DetectUrls = false;
            this->array_element_input->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold",8.25F,static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
            this->array_element_input->Location = System::Drawing::Point(12,145);
            this->array_element_input->Multiline = false;
            this->array_element_input->Name = L"array_element_input";
            this->array_element_input->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Horizontal;
            this->array_element_input->Size = System::Drawing::Size(248,32);
            this->array_element_input->TabIndex = 4;
            this->array_element_input->Text = L"Enter an element...";
            this->array_element_input->Click += gcnew System::EventHandler(this,&gui::onArrayElementInputClick);
            this->array_element_input->TextChanged += gcnew System::EventHandler(this,&gui::onElementInputTextChanged);
            // 
            // created_array_output
            // 
            this->created_array_output->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold",8.25F,static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0)));
            this->created_array_output->Location = System::Drawing::Point(266,12);
            this->created_array_output->Name = L"created_array_output";
            this->created_array_output->ReadOnly = true;
            this->created_array_output->Size = System::Drawing::Size(276,109);
            this->created_array_output->TabIndex = 5;
            this->created_array_output->Text = L"var <array_name> = [\"item1\", \"item2\", ...];";
            this->created_array_output->TextChanged += gcnew System::EventHandler(this,&gui::onCreatedArrayOutputTextChanged);
            // 
            // copy_array_btn
            // 
            this->copy_array_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->copy_array_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->copy_array_btn->Location = System::Drawing::Point(548,12);
            this->copy_array_btn->Name = L"copy_array_btn";
            this->copy_array_btn->Size = System::Drawing::Size(81,33);
            this->copy_array_btn->TabIndex = 6;
            this->copy_array_btn->Text = L"Copy []";
            this->copy_array_btn->UseVisualStyleBackColor = false;
            this->copy_array_btn->Click += gcnew System::EventHandler(this,&gui::onCopyCreatedArrayBtnClick);
            // 
            // add_array_element_btn
            // 
            this->add_array_element_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->add_array_element_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->add_array_element_btn->Location = System::Drawing::Point(141,207);
            this->add_array_element_btn->Name = L"add_array_element_btn";
            this->add_array_element_btn->Size = System::Drawing::Size(119,26);
            this->add_array_element_btn->TabIndex = 7;
            this->add_array_element_btn->Text = L"Add Element";
            this->add_array_element_btn->UseVisualStyleBackColor = false;
            this->add_array_element_btn->Click += gcnew System::EventHandler(this,&gui::onAddElementBtnClick);
            // 
            // element_type_lbl
            // 
            this->element_type_lbl->AutoSize = true;
            this->element_type_lbl->BackColor = System::Drawing::Color::Transparent;
            this->element_type_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold",9.75F,System::Drawing::FontStyle::Bold,System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->element_type_lbl->Location = System::Drawing::Point(12,180);
            this->element_type_lbl->Name = L"element_type_lbl";
            this->element_type_lbl->Size = System::Drawing::Size(89,17);
            this->element_type_lbl->TabIndex = 8;
            this->element_type_lbl->Text = L"Element Type";
            // 
            // element_type_comboBox
            // 
            this->element_type_comboBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->element_type_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->element_type_comboBox->FormattingEnabled = true;
            this->element_type_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
                L"String",L"Boolean",L"Number",L"Object",
L"Symbol",L"Undefined",L"Null"
            });
            this->element_type_comboBox->Location = System::Drawing::Point(107,180);
            this->element_type_comboBox->Name = L"element_type_comboBox";
            this->element_type_comboBox->Size = System::Drawing::Size(153,21);
            this->element_type_comboBox->TabIndex = 9;
            this->element_type_comboBox->Text = L"String";
            this->element_type_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this,&gui::onElementTypeIndexChanged);
            // ###########
            this->element_type_comboBox->TextChanged += gcnew System::EventHandler(this, &gui::onElementTypeTextChanged);
             // ###########
            // 
            // wrap_in_single_quotes_checkbox
            // 
            this->wrap_in_single_quotes_checkbox->AutoSize = true;
            this->wrap_in_single_quotes_checkbox->BackColor = System::Drawing::Color::Transparent;
            this->wrap_in_single_quotes_checkbox->Location = System::Drawing::Point(266,125);
            this->wrap_in_single_quotes_checkbox->Name = L"wrap_in_single_quotes_checkbox";
            this->wrap_in_single_quotes_checkbox->Size = System::Drawing::Size(137,17);
            this->wrap_in_single_quotes_checkbox->TabIndex = 18;
            this->wrap_in_single_quotes_checkbox->Text = L"Wrap in single quotes";
            this->wrap_in_single_quotes_checkbox->UseVisualStyleBackColor = false;
            this->wrap_in_single_quotes_checkbox->CheckedChanged += gcnew System::EventHandler(this,&gui::wrapInSingleQuotesCheckedChanged);
            // 
            // clear_created_array_output_btn
            // 
            this->clear_created_array_output_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->clear_created_array_output_btn->Location = System::Drawing::Point(548,50);
            this->clear_created_array_output_btn->Name = L"clear_created_array_output_btn";
            this->clear_created_array_output_btn->Size = System::Drawing::Size(81,33);
            this->clear_created_array_output_btn->TabIndex = 19;
            this->clear_created_array_output_btn->Text = L"Clear []";
            this->clear_created_array_output_btn->UseVisualStyleBackColor = true;
            this->clear_created_array_output_btn->Click += gcnew System::EventHandler(this,&gui::onClearCreatedArrayOutputBtnClick);
            // 
            // clear_all_btn
            // 
            this->clear_all_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->clear_all_btn->Location = System::Drawing::Point(548,88);
            this->clear_all_btn->Name = L"clear_all_btn";
            this->clear_all_btn->Size = System::Drawing::Size(81,33);
            this->clear_all_btn->TabIndex = 20;
            this->clear_all_btn->Text = L"Clear All";
            this->clear_all_btn->UseVisualStyleBackColor = true;
            this->clear_all_btn->Click += gcnew System::EventHandler(this,&gui::onClearAllClick);
            // 
            // make_array_object_checkbox
            // 
            this->make_array_object_checkbox->AutoSize = true;
            this->make_array_object_checkbox->BackColor = System::Drawing::Color::Transparent;
            this->make_array_object_checkbox->Location = System::Drawing::Point(409,125);
            this->make_array_object_checkbox->Name = L"make_array_object_checkbox";
            this->make_array_object_checkbox->Size = System::Drawing::Size(137,17);
            this->make_array_object_checkbox->TabIndex = 21;
            this->make_array_object_checkbox->Text = L"Use Array Constructor";
            this->make_array_object_checkbox->UseVisualStyleBackColor = false;
            this->make_array_object_checkbox->CheckedChanged += gcnew System::EventHandler(this,&gui::onUseArrayConstructorCheckedChanged);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)),static_cast<System::Int32>(static_cast<System::Byte>(223)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
            this->pictureBox1->Location = System::Drawing::Point(293,317);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(121,24);
            this->pictureBox1->TabIndex = 22;
            this->pictureBox1->TabStop = false;
            // 
            // gui
            // 
            this->AcceptButton = this->add_array_element_btn;
            this->AutoScaleDimensions = System::Drawing::SizeF(6,13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(641,344);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->make_array_object_checkbox);
            this->Controls->Add(this->clear_all_btn);
            this->Controls->Add(this->clear_created_array_output_btn);
            this->Controls->Add(this->wrap_in_single_quotes_checkbox);
            this->Controls->Add(this->element_type_comboBox);
            this->Controls->Add(this->element_type_lbl);
            this->Controls->Add(this->add_array_element_btn);
            this->Controls->Add(this->copy_array_btn);
            this->Controls->Add(this->created_array_output);
            this->Controls->Add(this->array_element_input);
            this->Controls->Add(this->create_array_btn);
            this->Controls->Add(this->exit_app_btn);
            this->Controls->Add(this->delete_array_element_btn);
            this->Controls->Add(this->array_elements_listview);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold",8.25F,System::Drawing::FontStyle::Bold,System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"gui";
            this->Text = L"JSArray[]";
            this->Load += gcnew System::EventHandler(this,&gui::onGUILoad);
            this->Shown += gcnew System::EventHandler(this,&gui::onGUIShown);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        System::Void onGUILoad(System::Object^  sender,System::EventArgs^  e) 
        {
    
        }

        System::Void onGUIShown(System::Object^  sender,System::EventArgs^  e) 
        {
            this->element_input_text = this->array_element_input->Text;
        }

        System::Void onDeleteElementBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
            ListView::CheckedListViewItemCollection^ checked_elements = this->array_elements_listview->CheckedItems;
            for each (ListViewItem^ lvi in checked_elements)
            {
                this->array_elements_listview->Items->Remove(lvi);
            }
        }

        System::Void onAddElementBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
            if(System::String::IsNullOrEmpty(this->element_input_text))
            {
                MessageBox::Show("Please enter an element first!");
            }
            else
            {
                if(this->use_quotation_marks == true)
                {
                    if(wrap_elements_with_single_quotes == true)
                    {
                        System::String^ full_element_name = this->open_quote + this->element_input_text + this->end_quote + this->element_delimeter;
                        this->new_list_view_element = (gcnew System::Windows::Forms::ListViewItem(full_element_name));
                        this->array_elements_listview->Items->Add(this->new_list_view_element);
                        this->array_element_input->Clear();
                    }
                    else
                    {
                        System::String^ full_element_name = this->open_double_quote + this->element_input_text + this->end_double_quote + this->element_delimeter;
                        this->new_list_view_element = (gcnew System::Windows::Forms::ListViewItem(full_element_name));
                        this->array_elements_listview->Items->Add(this->new_list_view_element);
                        this->array_element_input->Clear();
                    }
                }
                else
                {
                    System::String^ full_element_name = this->element_input_text + this->element_delimeter;
                    this->new_list_view_element = (gcnew System::Windows::Forms::ListViewItem(full_element_name));
                    this->array_elements_listview->Items->Add(this->new_list_view_element);
                    this->array_element_input->Clear();
                }
            }
        }

        System::Void onExitAppBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
           if(this->array_elements_listview->Items->Count == 0)
           {
                Application::Exit();
           }
           else
           {
                if(System::Windows::Forms::DialogResult::Yes == System::Windows::Forms::MessageBox::Show(
                    "Are you sure you would like to exit?", "Exit?",
                       System::Windows::Forms::MessageBoxButtons::YesNo,    System::Windows::Forms::MessageBoxIcon::Question, System::Windows::Forms::MessageBoxDefaultButton::Button1))
                {
                    Application::Exit();
                }
           }
        }

        System::Void onCreateArrayBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
            if(this->array_elements_listview->Items->Count == 0)
            {
                if(System::Windows::Forms::DialogResult::Yes == System::Windows::Forms::MessageBox::Show("No elements were entered. \n Would you like to create an empty array?",  "No elements added.",
                    System::Windows::Forms::MessageBoxButtons::YesNo, 
                    System::Windows::Forms::MessageBoxIcon::Question,
                    System::Windows::Forms::MessageBoxDefaultButton::Button1))
                {
                    this->create_empty_array = true;
                    this->full_element_string = "";
                    if(make_array_object_checkbox->Checked == false)
                    {
                        this->full_array_string = this->EMPTY_ARRAY_LITERAL;
                        this->created_array_output->Text = this->full_array_string;
                        this->array_is_created = true;
                    }
                    else
                    {
                        this->full_array_string = this->EMPTY_ARRAY_OBJECT;
                        this->created_array_output->Text = this->full_array_string;
                        this->array_is_created = true;
                    }
                }
                else
                {
                    this->array_is_created = false;
                }
            }
            else
            {
                this->create_empty_array = false;
                this->full_element_string = "";
                for(int index = 0; index < this->array_elements_listview->Items->Count; index++)
                {
                    this->full_element_string += this->array_elements_listview->Items[index]->Text;
                }
   
                int last_delimeter = full_element_string->LastIndexOf(this->element_delimeter);
  
                if(use_array_object == false)
                {
                    this->full_array_string = "var <array name> = [" + this->full_element_string->Remove(last_delimeter) + "];";
                }
                else
                {
                    this->full_array_string = "var <array name> = new Array(" + this->full_element_string->Remove(last_delimeter) + ");";
                }
                this->created_array_output->Text = this->full_array_string;
                this->array_elements_listview->Items->Clear();
                // Bug: 
                this->array_is_created = true;
            }
            
        }

        System::Void onCopyCreatedArrayBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
            this->created_array_output->SelectAll();
            this->created_array_output->Copy();
        }

        System::Void onClearCreatedArrayOutputBtnClick(System::Object^  sender,System::EventArgs^  e) 
        {
            if(this->use_array_object == true)
            {
               if(this->wrap_elements_with_single_quotes == true)
               {
                   //write the array object output hint to the output
                   //with the elements wrapped in single quotes.
                   this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("\"", "'");
               }
               else
               {
                   //write the array object output hint to the output
                   //with the elements wrapped in double quotes.
                   this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("'", "\"");
               }
           }
           else
           {
               if(this->wrap_elements_with_single_quotes == true)
               {
                   //write the array literal output hint to the output
                   //with the elements wrapped in single quotes.
                   this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("\"", "'");
               }
               else
               {
                   //write the array literal output hint to the output
                   //with the elements wrapped in double quotes.
                   this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("'", "\"");
               }
   
           }
        }

        System::Void onClearAllClick(System::Object^  sender,System::EventArgs^  e) 
        {
            this->created_array_output->Clear();

            if(this->array_element_input->Text->Length != 0)
            {
                this->array_element_input->Clear();
            }
            
            if(this->array_elements_listview->Items->Count != 0)
            {
                this->array_elements_listview->Items->Clear();
            }
            // Clear the element input text storage.
            this->element_input_text = nullptr;
            // Reset the flags that are not linked to a controler.
            this->create_empty_array = false;
            this->array_is_created = false;

        }

        System::Void onElementInputTextChanged(System::Object^  sender,System::EventArgs^  e) 
        {
            //Remove line in production version.
            Console::WriteLine(this->array_element_input->Text->Length);
 
            if(this->array_element_input->Text ==  this->ARRAY_ELEMENT_INPUT_HINT)
            {
                this->array_element_input->Clear();
            }
            this->element_input_text = this->array_element_input->Text;
    
        }

        System::Void onCreatedArrayOutputTextChanged(System::Object^  sender,System::EventArgs^  e) 
        {
            if(this->created_array_output->Text->Length == 0)
            {
                if(this->wrap_elements_with_single_quotes == true)
                {
                    if(this->use_array_object == true)
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("\"", "'");
                    }
                    else
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("\"", "'");
                    }
                }
                else
                {
                    if(this->use_array_object == true)
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("'", "\"");
                    }
                    else
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("'", "\"");
                    }
                }
            }
        }

        System::Void onArrayElementInputClick(System::Object^  sender,System::EventArgs^  e) {
            if(this->array_element_input->Text == this->ARRAY_ELEMENT_INPUT_HINT)
            {
                this->array_element_input->Clear();
            }
        }

        System::Void wrapInSingleQuotesCheckedChanged(System::Object^  sender,System::EventArgs^  e) 
        {
            this->wrap_elements_with_single_quotes = this->wrap_in_single_quotes_checkbox->Checked;

            if(this->array_is_created == true)
            {
                if(this->wrap_elements_with_single_quotes == true)
                {
                    String^ new_text = this->created_array_output->Text->Replace("\"", "'");
                    this->full_array_string = new_text;
                    this->created_array_output->Text = new_text;
                }
                else
                {
                    String^ new_text = this->created_array_output->Text->Replace("'", "\"");
                    this->full_array_string = new_text;
                    this->created_array_output->Text = new_text;
                }
            }
            else
            {
                if(this->wrap_elements_with_single_quotes == true)
                {
                    String^ new_text = this->created_array_output->Text->Replace("\"", "'");
                    this->full_array_string = new_text;
                    this->created_array_output->Text = new_text;
                }
                else
                {
                    String^ new_text = this->created_array_output->Text->Replace("'", "\"");
                    this->full_array_string = new_text;
                    this->created_array_output->Text = new_text;
                }
            }
        }

        System::Void onUseArrayConstructorCheckedChanged(System::Object^  sender, System::EventArgs^  e) 
        {
            if(this->make_array_object_checkbox->Checked == true)
            {
                this->use_array_object = true;
            }
            else
            {
                this->use_array_object = false;
            }

            if(array_is_created == true)
            {
                int last_delimeter = full_element_string->LastIndexOf(this->element_delimeter);

                if(this->wrap_elements_with_single_quotes == true)
                {
                    System::String^ new_full_element_string = this->full_element_string->Replace("\"", "'");
                    this->full_element_string = new_full_element_string;
                }
                else
                {
                    System::String^ new_full_element_string = this->full_element_string->Replace("'", "\"");
                    this->full_element_string = new_full_element_string;
                }
                if(this->make_array_object_checkbox->Checked == true)
                {
                    if(this->create_empty_array == true)
                    {
                        this->created_array_output->Text = this->EMPTY_ARRAY_OBJECT;
                    }
                    else
                    {
                        System::String^ array_object = "var <array name> = new Array(" + this->full_element_string->Remove(last_delimeter) + ");";
                        this->created_array_output->Clear();
                        this->created_array_output->Text = array_object;
                    }
                }
                else
                {
                    if(this->create_empty_array == true)
                    {
                        this->created_array_output->Text = this->EMPTY_ARRAY_LITERAL;
                    }
                    else
                    {
                        System::String^ array_object = "var <array name> = [" + this->full_element_string->Remove(last_delimeter) + "];";
                        this->created_array_output->Clear();
                        this->created_array_output->Text = array_object;
                    }
                }
            }
            else
            {
                if(this->wrap_elements_with_single_quotes == true)
                {
                    if(this->created_array_output->Text == this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT || this->created_array_output->Text == this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT_SINGLE)
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("\"", "'");
                    }
                    else
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("\"", "'");
                    }
                }
                else
                {
                    if(this->created_array_output->Text == this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT || this->created_array_output->Text == this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT_SINGLE)
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_OBJECT_HINT->Replace("'", "\"");
                    }
                    else
                    {
                        this->created_array_output->Text = this->CREATED_ARRAY_OUTPUT_ARRAY_LITERAL_HINT->Replace("'", "\"");
                    }
                }
            }
        }

        System::Void array_elements_listview_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
        {
   
        }

         // ###########
        System::Void onElementTypeIndexChanged(System::Object^  sender, System::EventArgs^  e) 
        {
            // TODO: Make it so that the entered array element has to match the selected element type. 
            // I have to do this for the rest of the element types.
            if(this->element_type_comboBox->Text == "String")
            {
                this->use_quotation_marks = true;
            }
            else
            {
                this->use_quotation_marks = false;
            }
        }
         // ###########

        // ###########
        System::Void onElementTypeTextChanged(System::Object^  sender, System::EventArgs^  e) {
            // The combobox doesn't have a ReadOnly property so I have to try to make it so 
            // the value can only be chosen from the listed values. The user should not be allowed to 
            // write a value. 
        }
        // ###########
};
}
