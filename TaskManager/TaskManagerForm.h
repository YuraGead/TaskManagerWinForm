#pragma once

// libs
#include <Windows.h>
#include <tlhelp32.h>
#include "psapi.h"
#include <msclr\marshal_cppstd.h>


namespace TaskManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TaskManagerForm : public System::Windows::Forms::Form
	{
	public:
		TaskManagerForm(void)
		{
			InitializeComponent();
		}

	protected:
		~TaskManagerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
		// Buttons
	private: System::Windows::Forms::Button^ bProc;
	private: System::Windows::Forms::Button^ bPID;
	private: System::Windows::Forms::Button^ bPIDF;
	private: System::Windows::Forms::Button^ bMem;
	private: System::Windows::Forms::Button^ bCpu;
	private: System::Windows::Forms::Button^ bPriority;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ killFamily;

	private: System::Windows::Forms::Button^ bChangePri;
	private: System::Windows::Forms::Button^ openFile;
		   // list view
	private: System::Windows::Forms::ListView^ lv_table;
		   // columns
	private: System::Windows::Forms::ColumnHeader^ columnProc;
	private: System::Windows::Forms::ColumnHeader^ columnPID;
	private: System::Windows::Forms::ColumnHeader^ columnPIDF;
	private: System::Windows::Forms::ColumnHeader^ columnMem;
	private: System::Windows::Forms::ColumnHeader^ columnCpu;
	private: System::Windows::Forms::ColumnHeader^ columnPriority;
		   // text boxes
	private: System::Windows::Forms::TextBox^ tbCpu;
	private: System::Windows::Forms::TextBox^ tbMem;
	private: System::Windows::Forms::TextBox^ filter;
	private: System::Windows::Forms::TextBox^ taskN;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ tbPri;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
		   // timer
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:


// BEGINNING OF THE GENERATED CODE


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bProc = (gcnew System::Windows::Forms::Button());
			this->bPID = (gcnew System::Windows::Forms::Button());
			this->bPIDF = (gcnew System::Windows::Forms::Button());
			this->bMem = (gcnew System::Windows::Forms::Button());
			this->bCpu = (gcnew System::Windows::Forms::Button());
			this->bPriority = (gcnew System::Windows::Forms::Button());
			this->lv_table = (gcnew System::Windows::Forms::ListView());
			this->columnProc = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnPID = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnPIDF = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnMem = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnCpu = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnPriority = (gcnew System::Windows::Forms::ColumnHeader());
			this->tbCpu = (gcnew System::Windows::Forms::TextBox());
			this->tbMem = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->killFamily = (gcnew System::Windows::Forms::Button());
			this->filter = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tbPri = (gcnew System::Windows::Forms::TextBox());
			this->bChangePri = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->openFile = (gcnew System::Windows::Forms::Button());
			this->taskN = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// bProc
			// 
			this->bProc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bProc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bProc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bProc->Location = System::Drawing::Point(0, 71);
			this->bProc->Name = L"bProc";
			this->bProc->Size = System::Drawing::Size(150, 30);
			this->bProc->TabIndex = 1;
			this->bProc->Text = L"Process";
			this->bProc->UseVisualStyleBackColor = true;
			this->bProc->Click += gcnew System::EventHandler(this, &TaskManagerForm::bProc_Click);
			// 
			// bPID
			// 
			this->bPID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bPID->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bPID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bPID->Location = System::Drawing::Point(150, 71);
			this->bPID->Name = L"bPID";
			this->bPID->Size = System::Drawing::Size(70, 30);
			this->bPID->TabIndex = 2;
			this->bPID->Text = L"PID";
			this->bPID->UseVisualStyleBackColor = true;
			this->bPID->Click += gcnew System::EventHandler(this, &TaskManagerForm::bPID_Click);
			// 
			// bPIDF
			// 
			this->bPIDF->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bPIDF->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bPIDF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bPIDF->Location = System::Drawing::Point(220, 71);
			this->bPIDF->Name = L"bPIDF";
			this->bPIDF->Size = System::Drawing::Size(70, 30);
			this->bPIDF->TabIndex = 3;
			this->bPIDF->Text = L"Family PID";
			this->bPIDF->UseVisualStyleBackColor = true;
			this->bPIDF->Click += gcnew System::EventHandler(this, &TaskManagerForm::bPIDF_Click);
			// 
			// bMem
			// 
			this->bMem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bMem->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bMem->Location = System::Drawing::Point(290, 71);
			this->bMem->Name = L"bMem";
			this->bMem->Size = System::Drawing::Size(70, 30);
			this->bMem->TabIndex = 4;
			this->bMem->Text = L"Memory";
			this->bMem->UseVisualStyleBackColor = true;
			this->bMem->Click += gcnew System::EventHandler(this, &TaskManagerForm::bMem_Click);
			// 
			// bCpu
			// 
			this->bCpu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bCpu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bCpu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bCpu->Location = System::Drawing::Point(360, 71);
			this->bCpu->Name = L"bCpu";
			this->bCpu->Size = System::Drawing::Size(50, 30);
			this->bCpu->TabIndex = 5;
			this->bCpu->Text = L"CPU";
			this->bCpu->UseVisualStyleBackColor = true;
			this->bCpu->Click += gcnew System::EventHandler(this, &TaskManagerForm::bCpu_Click);
			// 
			// bPriority
			// 
			this->bPriority->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bPriority->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bPriority->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bPriority->Location = System::Drawing::Point(410, 71);
			this->bPriority->Name = L"bPriority";
			this->bPriority->Size = System::Drawing::Size(90, 30);
			this->bPriority->TabIndex = 6;
			this->bPriority->Text = L"Priority";
			this->bPriority->UseVisualStyleBackColor = true;
			this->bPriority->Click += gcnew System::EventHandler(this, &TaskManagerForm::bPriority_Click);
			// 
			// lv_table
			// 
			this->lv_table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->lv_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnProc, this->columnPID,
					this->columnPIDF, this->columnMem, this->columnCpu, this->columnPriority
			});
			this->lv_table->FullRowSelect = true;
			this->lv_table->GridLines = true;
			this->lv_table->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->lv_table->HideSelection = false;
			this->lv_table->Location = System::Drawing::Point(0, 101);
			this->lv_table->MultiSelect = false;
			this->lv_table->Name = L"lv_table";
			this->lv_table->Size = System::Drawing::Size(500, 418);
			this->lv_table->TabIndex = 7;
			this->lv_table->UseCompatibleStateImageBehavior = false;
			this->lv_table->View = System::Windows::Forms::View::Details;
			// 
			// columnProc
			// 
			this->columnProc->Width = 148;
			// 
			// columnPID
			// 
			this->columnPID->Width = 70;
			// 
			// columnPIDF
			// 
			this->columnPIDF->Width = 70;
			// 
			// columnMem
			// 
			this->columnMem->Width = 70;
			// 
			// columnCpu
			// 
			this->columnCpu->Width = 50;
			// 
			// columnPriority
			// 
			this->columnPriority->Width = 85;
			// 
			// tbCpu
			// 
			this->tbCpu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbCpu->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbCpu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbCpu->Location = System::Drawing::Point(360, 46);
			this->tbCpu->Multiline = true;
			this->tbCpu->Name = L"tbCpu";
			this->tbCpu->ReadOnly = true;
			this->tbCpu->Size = System::Drawing::Size(50, 25);
			this->tbCpu->TabIndex = 8;
			this->tbCpu->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbCpu->WordWrap = false;
			// 
			// tbMem
			// 
			this->tbMem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbMem->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMem->Location = System::Drawing::Point(290, 46);
			this->tbMem->Multiline = true;
			this->tbMem->Name = L"tbMem";
			this->tbMem->ReadOnly = true;
			this->tbMem->Size = System::Drawing::Size(70, 25);
			this->tbMem->TabIndex = 9;
			this->tbMem->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMem->WordWrap = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &TaskManagerForm::timer1_Tick);
			// 
			// button1 refresh button
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(0, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 50);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Refresh";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TaskManagerForm::button1_Click);
			// 
			// button2 kill process
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(150, 21);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 50);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Kill process";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TaskManagerForm::button2_Click);
			// 
			// killFamily
			// 
			this->killFamily->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->killFamily->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->killFamily->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->killFamily->Location = System::Drawing::Point(220, 21);
			this->killFamily->Name = L"killFamily";
			this->killFamily->Size = System::Drawing::Size(70, 50);
			this->killFamily->TabIndex = 12;
			this->killFamily->Text = L"Kill family";
			this->killFamily->UseVisualStyleBackColor = true;
			this->killFamily->Click += gcnew System::EventHandler(this, &TaskManagerForm::button3_Click);
			// 
			// filter
			// 
			this->filter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->filter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->filter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->filter->Location = System::Drawing::Point(74, 46);
			this->filter->Multiline = true;
			this->filter->Name = L"filter";
			this->filter->Size = System::Drawing::Size(76, 25);
			this->filter->TabIndex = 13;
			this->filter->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->filter->WordWrap = false;
			this->filter->TextChanged += gcnew System::EventHandler(this, &TaskManagerForm::textBox1_TextChanged);
			// 
			// textBox2 Filter
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->textBox2->Location = System::Drawing::Point(74, 21);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(76, 25);
			this->textBox2->TabIndex = 14;
			this->textBox2->Text = L"Filter";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->WordWrap = false;
			// 
			// tbPri
			// 
			this->tbPri->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbPri->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbPri->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->tbPri->Location = System::Drawing::Point(453, 46);
			this->tbPri->Multiline = true;
			this->tbPri->Name = L"tbPri";
			this->tbPri->Size = System::Drawing::Size(47, 25);
			this->tbPri->TabIndex = 15;
			this->tbPri->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPri->WordWrap = false;
			// 
			// bChangePri
			// 
			this->bChangePri->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->bChangePri->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bChangePri->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bChangePri->Location = System::Drawing::Point(410, 21);
			this->bChangePri->Name = L"bChangePri";
			this->bChangePri->Size = System::Drawing::Size(90, 25);
			this->bChangePri->TabIndex = 16;
			this->bChangePri->Text = L"Change priority";
			this->bChangePri->UseVisualStyleBackColor = true;
			this->bChangePri->Click += gcnew System::EventHandler(this, &TaskManagerForm::bChangePri_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->textBox1->Location = System::Drawing::Point(410, 46);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(44, 25);
			this->textBox1->TabIndex = 17;
			this->textBox1->Text = L"0-5";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->WordWrap = false;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(290, 21);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(120, 25);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"Priority: 0 > 5 ------->";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->WordWrap = false;
			// 
			// openFile
			// 
			this->openFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->openFile->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->openFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openFile->Location = System::Drawing::Point(0, 0);
			this->openFile->Name = L"openFile";
			this->openFile->Size = System::Drawing::Size(150, 21);
			this->openFile->TabIndex = 21;
			this->openFile->Text = L"Create new task";
			this->openFile->UseVisualStyleBackColor = true;
			this->openFile->Click += gcnew System::EventHandler(this, &TaskManagerForm::openFile_Click);
			// 
			// taskN
			// 
			this->taskN->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->taskN->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->taskN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->taskN->Location = System::Drawing::Point(150, 0);
			this->taskN->Multiline = true;
			this->taskN->Name = L"taskN";
			this->taskN->Size = System::Drawing::Size(140, 21);
			this->taskN->TabIndex = 22;
			this->taskN->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->taskN->WordWrap = false;
			// 
			// TaskManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 520);
			this->Controls->Add(this->taskN);
			this->Controls->Add(this->openFile);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->bChangePri);
			this->Controls->Add(this->tbPri);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->filter);
			this->Controls->Add(this->killFamily);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbMem);
			this->Controls->Add(this->tbCpu);
			this->Controls->Add(this->bPriority);
			this->Controls->Add(this->bCpu);
			this->Controls->Add(this->bMem);
			this->Controls->Add(this->bPIDF);
			this->Controls->Add(this->bPID);
			this->Controls->Add(this->bProc);
			this->Controls->Add(this->lv_table);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximumSize = System::Drawing::Size(516, 559);
			this->MinimumSize = System::Drawing::Size(516, 559);
			this->Name = L"TaskManagerForm";
			this->ShowIcon = false;
			this->Text = L"Task Manager";
			this->Load += gcnew System::EventHandler(this, &TaskManagerForm::TaskManagerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


// END OF GENERATED CODE


		// Class for sorting listview on click                         
		ref class ListViewItemComparer : public System::Collections::IComparer
		{
		private:
			int col;
			SortOrder ord;
		public:
			ListViewItemComparer()
			{
				col = 0;
				ord = SortOrder::Ascending;
			}

			ListViewItemComparer(int column, SortOrder order)
			{
				col = column;
				ord = order;
			}

			virtual int Compare(Object^ x, Object^ y)
			{
				int result;
				//  alphabetic order           
				if (col == 0) {
					result = System::String::Compare((dynamic_cast<System::Windows::Forms::ListViewItem^>(x))->SubItems[col]->Text,
						(dynamic_cast<System::Windows::Forms::ListViewItem^>(y))->SubItems[col]->Text);
					if (ord == SortOrder::Ascending) {
						return result;
					}
					else {
						return result * -1;
					}
				}
				// numeric order   
				else if (col >= 1 && col <= 2) {
					int a = Int32::Parse((dynamic_cast<System::Windows::Forms::ListViewItem^>(x))->SubItems[col]->Text);
					int b = Int32::Parse((dynamic_cast<System::Windows::Forms::ListViewItem^>(y))->SubItems[col]->Text);
					if (a < b) {
						result = -1;
					}
					else if (a == b) {
						result = 0;
					}
					else if (a > b) {
						result = 1;
					}
					if (ord == SortOrder::Ascending) {
						return result;
					}
					else {
						return result * -1;
					}
				}
				// for float       
				else if (col == 3) {
					String^ aStr = (dynamic_cast<System::Windows::Forms::ListViewItem^>(x))->SubItems[col]->Text;
					String^ bStr = (dynamic_cast<System::Windows::Forms::ListViewItem^>(y))->SubItems[col]->Text;
					aStr = aStr->Remove(aStr->Length - 3, 3);
					bStr = bStr->Remove(bStr->Length - 3, 3);
					double a = Double::Parse(aStr);
					double b = Double::Parse(bStr);
					if (a < b) {
						result = -1;
					}
					else {
						result = 1;
					}
					if (ord == SortOrder::Ascending) {
						return result;
					}
					else {
						return result * -1;
					}
				}
				// priority order             
				else if (col == 5) {
					//IDLE, BELOW NORMAL, NORMAL, ABOVE NORMAL, HIGH, REALTIME
					String^ aStr = (dynamic_cast<System::Windows::Forms::ListViewItem^>(x))->SubItems[col]->Text;
					String^ bStr = (dynamic_cast<System::Windows::Forms::ListViewItem^>(y))->SubItems[col]->Text;
					int a;
					int b;
					// a
					if (aStr == "Realtime") {
						a = 0;
					}
					if (aStr == "High") {
						a = 1;
					}
					if (aStr == "Above normal") {
						a = 2;
					}
					if (aStr == "Normal") {
						a = 3;
					}
					if (aStr == "Below normal") {
						a = 4;
					}
					if (aStr == "Idle") {
						a = 5;
					}
					// b
					if (bStr == "Realtime") {
						b = 0;
					}
					if (bStr == "High") {
						b = 1;
					}
					if (bStr == "Above normal") {
						b = 2;
					}
					if (bStr == "Normal") {
						b = 3;
					}
					if (bStr == "Below normal") {
						b = 4;
					}
					if (bStr == "Idle") {
						b = 5;
					}

					// compare
					if (a < b) {
						result = 1;
					}
					else {
						result = -1;
					}
					if (ord == SortOrder::Ascending) {
						return result;
					}
					else {
						return result * -1;
					}
				}
			}
		};
		// for privilege
		NTSTATUS EnablePrivilege(wchar_t* privilege)
		{
			HANDLE token;
			TOKEN_PRIVILEGES* tp = NULL;
			if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &token))
				goto error;

			tp = (TOKEN_PRIVILEGES*)new char[offsetof(TOKEN_PRIVILEGES, Privileges[1])];
			if (!tp)
				goto error;
			tp->PrivilegeCount = 1;
			tp->Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			if (!LookupPrivilegeValueW(0, privilege, &tp->Privileges[0].Luid))
				goto error;

			if (!AdjustTokenPrivileges(token, 0, tp, 0, 0, 0) || GetLastError() != ERROR_SUCCESS)
				goto error;

			CloseHandle(token);

			return 0x0;
		error:
			if (tp)
				delete[] tp;

			return 0xC0000001;
		}
		// refresh listview and save filter
		void updateList(String^ value)
		{
			String^ value1 = filter->Text;
			value = value1;
			lv_table->Items->Clear();
			getProcesses(value);
		}

		// kill the familty of processes
		void terminateFamily(DWORD familyPID)
		{
			HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (snapshot == INVALID_HANDLE_VALUE) {
				return;
			}

			PROCESSENTRY32 processEntry;
			processEntry.dwSize = sizeof(PROCESSENTRY32);

			if (Process32First(snapshot, &processEntry)) {
				do {
					if (processEntry.th32ParentProcessID == familyPID) {
						const auto explorer = OpenProcess(PROCESS_TERMINATE, false, processEntry.th32ProcessID);
						TerminateProcess(explorer, 1);
						CloseHandle(explorer);
					}
				} while (Process32Next(snapshot, &processEntry));
			}
			CloseHandle(snapshot);
		}

		// show processes in listview with value filter
		void getProcesses(String^ value) {
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			PROCESSENTRY32 pe;  //                                     
			PROCESS_MEMORY_COUNTERS_EX pmc;
			pe.dwSize = sizeof(PROCESSENTRY32);
			if (Process32First(hSnapshot, &pe)) {
				do
				{
					if (!pe.th32ProcessID) continue;    // skip [System process]

					HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION,
						FALSE, pe.th32ProcessID);    // get process descriptor 
					// memory that process uses
					PROCESS_MEMORY_COUNTERS_EX pmc;
					GetProcessMemoryInfo(hProcess, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
					SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
					// ##################################

					char cPriority[18];
					switch (GetPriorityClass(hProcess)) // get process priority
					{

					case IDLE_PRIORITY_CLASS:
						strcpy(cPriority, "Idle");
						break;
					case BELOW_NORMAL_PRIORITY_CLASS:
						strcpy(cPriority, "Below normal");
						break;
					case NORMAL_PRIORITY_CLASS:
						strcpy(cPriority, "Normal");
						break;
					case ABOVE_NORMAL_PRIORITY_CLASS:
						strcpy(cPriority, "Above normal");
						break;
					case HIGH_PRIORITY_CLASS:
						strcpy(cPriority, "High");
						break;
					case REALTIME_PRIORITY_CLASS:
						strcpy(cPriority, "Realtime");
						break;
					default:
						strcpy(cPriority, "Normal");
					}
					CloseHandle(hProcess);
					// show process information
					array<String^>^ row = gcnew array<String^>(6);

					std::string PID = std::to_string(pe.th32ProcessID);
					String^ SPID = gcnew String(PID.c_str());
					std::string FPID = std::to_string(pe.th32ParentProcessID);
					String^ SFPID = gcnew String(FPID.c_str());
					std::string Mem = std::to_string(physMemUsedByMe / 1024 / 1024);
					Mem = Mem + "   ";
					String^ SMem = gcnew String(Mem.c_str());


					row[0] = gcnew String(pe.szExeFile);
					row[1] = SPID;
					row[2] = SFPID;
					row[3] = SMem;
					row[4] = "";
					row[5] = gcnew String(cPriority);

					ListViewItem^ lv1 = gcnew ListViewItem(row);
					String^ s = lv1->Text;
					s = s->ToLower();
					String^ value1 = value->ToLower();
					if (s->Contains(value1) || value == "") {
						lv_table->Items->Add(lv1);
					}


				} while (Process32Next(hSnapshot, &pe));  // search for the next process in snapshot
			}
			CloseHandle(hSnapshot);
		}
		// func for cpu load
		static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
		{
			static unsigned long long _previousTotalTicks = 0;
			static unsigned long long _previousIdleTicks = 0;

			unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
			unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

			float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

			_previousTotalTicks = totalTicks;
			_previousIdleTicks = idleTicks;
			return ret;
		}

		// converting FILETIME to unsigned long long
		static unsigned long long FileTimeToInt64(const FILETIME& ft) { return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime); }

		// CPU load calculations
		float GetCPULoad()
		{
			FILETIME idleTime, kernelTime, userTime;
			return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime),
				FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
		}
	private: System::Void TaskManagerForm_Load(System::Object^ sender, System::EventArgs^ e) {

		// CPU load
		float fCpu = GetCPULoad() * 1000;
		char cCpu[4];
		sprintf(cCpu, "%.1lf\n", fCpu);
		strcat(cCpu, "%");
		String^ sCpu = gcnew String(cCpu);
		tbCpu->Text = sCpu;

		// Memory
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG memoryLoad = memInfo.dwMemoryLoad;
		std::string sMem = std::to_string(memoryLoad);
		sMem = sMem + " %";
		String^ SMem = gcnew String(sMem.c_str());
		tbMem->Text = SMem;

		// ListView default sort
		lv_table->Sorting = SortOrder::Ascending;
		getProcesses("");

		// Timer start
		timer1->Start();
	}

		   // Timer
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// CPU load
		float fCpu = GetCPULoad() * 1000;
		char cCpu[4];
		sprintf(cCpu, "%.1lf", fCpu);
		strcat(cCpu, "%");
		String^ sCpu = gcnew String(cCpu);
		tbCpu->Text = sCpu;

		// Memory
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG memoryLoad = memInfo.dwMemoryLoad;
		std::string sMem = std::to_string(memoryLoad);
		sMem = sMem + " %";
		String^ SMem = gcnew String(sMem.c_str());
		tbMem->Text = SMem;


	}

		   // Buttons above columns
		   // 
		   //BEGIN ######################################################
		   SortOrder orderProc = SortOrder::Ascending;
		   SortOrder orderPID = SortOrder::Descending;
		   SortOrder orderPIDF = SortOrder::Descending;
		   SortOrder orderMem = SortOrder::Descending;
		   SortOrder orderCpu = SortOrder::Descending;
		   SortOrder orderPri = SortOrder::Descending;
	private: System::Void bProc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderProc == SortOrder::Descending) {
			orderProc = SortOrder::Ascending;
		}
		else {
			orderProc = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(0, orderProc);
		orderPID = SortOrder::Descending;
		orderPIDF = SortOrder::Descending;
		orderMem = SortOrder::Descending;
		orderCpu = SortOrder::Descending;
		orderPri = SortOrder::Descending;
	}

	private: System::Void bPID_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderPID == SortOrder::Descending) {
			orderPID = SortOrder::Ascending;
		}
		else {
			orderPID = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(1, orderPID);
		orderProc = SortOrder::Descending;
		orderPIDF = SortOrder::Descending;
		orderMem = SortOrder::Descending;
		orderCpu = SortOrder::Descending;
		orderPri = SortOrder::Descending;
	}

	private: System::Void bPIDF_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderPIDF == SortOrder::Descending) {
			orderPIDF = SortOrder::Ascending;
		}
		else {
			orderPIDF = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(2, orderPIDF);
		orderProc = SortOrder::Descending;
		orderPID = SortOrder::Descending;
		orderMem = SortOrder::Descending;
		orderCpu = SortOrder::Descending;
		orderPri = SortOrder::Descending;
	}

	private: System::Void bMem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderMem == SortOrder::Descending) {
			orderMem = SortOrder::Ascending;
		}
		else {
			orderMem = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(3, orderMem);
		orderProc = SortOrder::Descending;
		orderPID = SortOrder::Descending;
		orderPIDF = SortOrder::Descending;
		orderCpu = SortOrder::Descending;
		orderPri = SortOrder::Descending;
	}

	private: System::Void bCpu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderCpu == SortOrder::Descending) {
			orderCpu = SortOrder::Ascending;
		}
		else {
			orderCpu = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(4, orderCpu);
		orderProc = SortOrder::Descending;
		orderPID = SortOrder::Descending;
		orderPIDF = SortOrder::Descending;
		orderMem = SortOrder::Descending;
		orderPri = SortOrder::Descending;
	}

	private: System::Void bPriority_Click(System::Object^ sender, System::EventArgs^ e) {
		if (orderPri == SortOrder::Descending) {
			orderPri = SortOrder::Ascending;
		}
		else {
			orderPri = SortOrder::Descending;
		}
		lv_table->ListViewItemSorter = gcnew ListViewItemComparer(5, orderPri);
		orderProc = SortOrder::Descending;
		orderPID = SortOrder::Descending;
		orderPIDF = SortOrder::Descending;
		orderMem = SortOrder::Descending;
		orderCpu = SortOrder::Descending;
	}

		   //END#######################################################

	// button - refresh
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		updateList("");
	}

		   // button - kill process
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lv_table->SelectedItems->Count > 0) {
			String^ selectedProcessID = lv_table->SelectedItems[0]->SubItems[1]->Text;
			if (selectedProcessID == "0") {
			}
			else {
				std::string str = msclr::interop::marshal_as<std::string>(selectedProcessID);
				NTSTATUS result = EnablePrivilege(SE_DEBUG_NAME);
				const auto explorer = OpenProcess(PROCESS_TERMINATE, false, atoi(str.c_str()));
				TerminateProcess(explorer, 1);
				String^ value = filter->Text;
				CloseHandle(explorer);
				updateList(value);
			}
		}
	}

		   //  button - kill family of processes
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lv_table->SelectedItems->Count > 0) {
			String^ selectedProcessFID = lv_table->SelectedItems[0]->SubItems[2]->Text;
			std::string str = msclr::interop::marshal_as<std::string>(selectedProcessFID);
			int FID = atoi(str.c_str());
			NTSTATUS result = EnablePrivilege(SE_DEBUG_NAME);
			terminateFamily(FID);
			String^ value = filter->Text;
			updateList(value);
		}
	}

		   // change filter text
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ value = filter->Text;
		updateList(value);
	}

		   // button - change priority
	private: System::Void bChangePri_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lv_table->SelectedItems->Count > 0) {
			String^ value = tbPri->Text;
			std::string str1 = msclr::interop::marshal_as<std::string>(value);
			int iValue = atoi(str1.c_str());

			String^ filt = filter->Text;

			String^ selectedProcessPID = lv_table->SelectedItems[0]->SubItems[1]->Text;
			std::string str = msclr::interop::marshal_as<std::string>(selectedProcessPID);
			int PID = atoi(str.c_str());
			HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_SET_INFORMATION,
				FALSE, PID);

			DWORD priority;
			switch (iValue) {
			case (0):
				priority = REALTIME_PRIORITY_CLASS;
				break;
			case (1):
				priority = HIGH_PRIORITY_CLASS;
				break;
			case (2):
				priority = ABOVE_NORMAL_PRIORITY_CLASS;
				break;
			case (3):
				priority = NORMAL_PRIORITY_CLASS;
				break;
			case (4):
				priority = BELOW_NORMAL_PRIORITY_CLASS;
				break;
			case (5):
				priority = IDLE_PRIORITY_CLASS;
				break;
			default:
				priority = NULL;
				break;
			}
			if (priority != NULL) {
				SetPriorityClass(hProcess, priority);
				updateList(filt);
			}
		}
	}
	// create new process                 
	private: System::Void openFile_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ value = taskN->Text;
		if (value == "") {
			System::IO::Stream^ myStream;
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

			openFileDialog->InitialDirectory = "C:\\Windows";
			openFileDialog->Filter = "Executables (*.exe)|*.exe";
			openFileDialog->FilterIndex = 1;
			openFileDialog->RestoreDirectory = true;

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = openFileDialog->OpenFile()) != nullptr)
				{
					STARTUPINFO si;
					ZeroMemory(&si, sizeof(si));
					PROCESS_INFORMATION pi;

					String^ str = openFileDialog->FileName;
					std::wstring wideString = msclr::interop::marshal_as<std::wstring>(str);
					LPCWSTR str1 = wideString.c_str();
					CreateProcess(str1, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
					myStream->Close();
				}
			}
		}
		else {
			STARTUPINFO si;
			ZeroMemory(&si, sizeof(si));
			PROCESS_INFORMATION pi;
			value = "C:\\Windows\\" + value;
			std::wstring wideString = msclr::interop::marshal_as<std::wstring>(value);
			LPCWSTR str1 = wideString.c_str();
			if (!CreateProcess(str1, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi)) {
				taskN->Text = "";
				System::IO::Stream^ myStream;
				OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

				openFileDialog->InitialDirectory = "C:\\Windows";
				openFileDialog->Filter = "Executables (*.exe)|*.exe";
				openFileDialog->FilterIndex = 1;
				openFileDialog->RestoreDirectory = true;

				if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					if ((myStream = openFileDialog->OpenFile()) != nullptr)
					{
						STARTUPINFO si;
						ZeroMemory(&si, sizeof(si));
						PROCESS_INFORMATION pi;

						String^ str = openFileDialog->FileName;
						std::wstring wideString = msclr::interop::marshal_as<std::wstring>(str);
						LPCWSTR str1 = wideString.c_str();
						CreateProcess(str1, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
						myStream->Close();

					}
				}
			}
		}
	}
	};
}