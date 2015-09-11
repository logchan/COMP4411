//
// impressionistUI.h
//
// The user interface part for the program.
//


#include <FL/fl_ask.h>

#include <math.h>

#include "impressionistUI.h"
#include "impressionistDoc.h"

/*
//------------------------------ Widget Examples -------------------------------------------------
Here is some example code for all of the widgets that you may need to add to the 
project.  You can copy and paste these into your code and then change them to 
make them look how you want.  Descriptions for all of the widgets here can be found 
in links on the fltk help session page.

//---------Window/Dialog and Menubar-----------------------------------
	
	//----To install a window--------------------------
	Fl_Window* myWindow = new Fl_Window(600, 300, "MyWindow");
		myWindow->user_data((void*)(this));	// record self to be used by static callback functions
		
		// install menu bar
		myMenubar = new Fl_Menu_Bar(0, 0, 600, 25);
		Fl_Menu_Item ImpressionistUI::myMenuItems[] = {
			{ "&File",		0, 0, 0, FL_SUBMENU },
				{ "&Load...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load },
				{ "&Save...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save }.
				{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
				{ 0 },
			{ "&Edit",		0, 0, 0, FL_SUBMENU },
				{ "&Copy",FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_copy, (void *)COPY },
				{ "&Cut",	FL_ALT + 'x', (Fl_Callback *)ImpressionistUI::cb_cut, (void *)CUT },
				{ "&Paste",	FL_ALT + 'v', (Fl_Callback *)ImpressionistUI::cb_paste, (void *)PASTE },
				{ 0 },
			{ "&Help",		0, 0, 0, FL_SUBMENU },
				{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
				{ 0 },
			{ 0 }
		};
		myMenubar->menu(myMenuItems);
    m_mainWindow->end();

	//----The window callback--------------------------
	// One of the callbacks
	void ImpressionistUI::cb_load(Fl_Menu_* o, void* v) 
	{	
		ImpressionistDoc *pDoc=whoami(o)->getDocument();

		char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
		if (newfile != NULL) {
			pDoc->loadImage(newfile);
		}
	}


//------------Slider---------------------------------------

	//----To install a slider--------------------------
	Fl_Value_Slider * mySlider = new Fl_Value_Slider(10, 80, 300, 20, "My Value");
	mySlider->user_data((void*)(this));	// record self to be used by static callback functions
	mySlider->type(FL_HOR_NICE_SLIDER);
    mySlider->labelfont(FL_COURIER);
    mySlider->labelsize(12);
	mySlider->minimum(1);
	mySlider->maximum(40);
	mySlider->step(1);
	mySlider->value(m_nMyValue);
	mySlider->align(FL_ALIGN_RIGHT);
	mySlider->callback(cb_MyValueSlides);

	//----The slider callback--------------------------
	void ImpressionistUI::cb_MyValueSlides(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyValue=int( ((Fl_Slider *)o)->value() ) ;
	}
	

//------------Choice---------------------------------------
	
	//----To install a choice--------------------------
	Fl_Choice * myChoice = new Fl_Choice(50,10,150,25,"&myChoiceLabel");
	myChoice->user_data((void*)(this));	 // record self to be used by static callback functions
	Fl_Menu_Item ImpressionistUI::myChoiceMenu[3+1] = {
	  {"one",FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)ONE},
	  {"two",FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)TWO},
	  {"three",FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)THREE},
	  {0}
	};
	myChoice->menu(myChoiceMenu);
	myChoice->callback(cb_myChoice);
	
	//-----The choice callback-------------------------
	void ImpressionistUI::cb_myChoice(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
		ImpressionistDoc* pDoc=pUI->getDocument();

		int type=(int)v;

		pDoc->setMyType(type);
	}


//------------Button---------------------------------------

	//---To install a button---------------------------
	Fl_Button* myButton = new Fl_Button(330,220,50,20,"&myButtonLabel");
	myButton->user_data((void*)(this));   // record self to be used by static callback functions
	myButton->callback(cb_myButton);

	//---The button callback---------------------------
	void ImpressionistUI::cb_myButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI*)(o->user_data()));
		ImpressionistDoc* pDoc = pUI->getDocument();
		pDoc->startPainting();
	}


//---------Light Button------------------------------------
	
	//---To install a light button---------------------
	Fl_Light_Button* myLightButton = new Fl_Light_Button(240,10,150,25,"&myLightButtonLabel");
	myLightButton->user_data((void*)(this));   // record self to be used by static callback functions
	myLightButton->callback(cb_myLightButton);

	//---The light button callback---------------------
	void ImpressionistUI::cb_myLightButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

		if (pUI->myBool==TRUE) pUI->myBool=FALSE;
		else pUI->myBool=TRUE;
	}

//----------Int Input--------------------------------------

    //---To install an int input-----------------------
	Fl_Int_Input* myInput = new Fl_Int_Input(200, 50, 5, 5, "&My Input");
	myInput->user_data((void*)(this));   // record self to be used by static callback functions
	myInput->callback(cb_myInput);

	//---The int input callback------------------------
	void ImpressionistUI::cb_myInput(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyInputValue=int( ((Fl_Int_Input *)o)->value() );
	}

//------------------------------------------------------------------------------------------------
*/

//------------------------------------- Help Functions --------------------------------------------

//------------------------------------------------------------
// This returns the UI, given the menu item.  It provides a
// link from the menu items to the UI
//------------------------------------------------------------
ImpressionistUI* ImpressionistUI::whoami(Fl_Menu_* o)	
{
	return ( (ImpressionistUI*)(o->parent()->user_data()) );
}


//--------------------------------- Callback Functions --------------------------------------------

//------------------------------------------------------------------
// Brings up a file chooser and then loads the chosen image
// This is called by the UI when the load image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_load_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}


//------------------------------------------------------------------
// Brings up a file chooser and then saves the painted image
// This is called by the UI when the save image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_save_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Save File?", "*.bmp", "save.bmp" );
	if (newfile != NULL) {
		pDoc->saveImage(newfile);
	}
}

//-------------------------------------------------------------
// Brings up the paint dialog
// This is called by the UI when the brushes menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_brushes(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_brushDialog->show();
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();

	pDoc->clearCanvas();
}

//------------------------------------------------------------
// Causes the Impressionist program to exit
// Called by the UI when the quit menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_exit(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_mainWindow->hide();
	whoami(o)->m_brushDialog->hide();

}



//-----------------------------------------------------------
// Brings up an about dialog box
// Called by the UI when the about menu item is chosen
//-----------------------------------------------------------
void ImpressionistUI::cb_about(Fl_Menu_* o, void* v) 
{
	fl_message("Impressionist FLTK version for CS341, Spring 2002");
}

void ImpressionistUI::cb_undo(Fl_Menu_* o, void* v) {
	ImpressionistUI* pUI = whoami(o);
	ImpressionistDoc* pDoc = pUI->getDocument();

	pDoc->undo();
}


//------- UI should keep track of the current for all the controls for answering the query from Doc ---------
//-------------------------------------------------------------
// Sets the type of brush to use to the one chosen in the brush 
// choice.  
// Called by the UI when a brush is chosen in the brush choice
//-------------------------------------------------------------
void ImpressionistUI::cb_brushChoice(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc=pUI->getDocument();

	int type=(int)v;


	pDoc->setBrushType(type);
}
void ImpressionistUI::cb_StrokeDirectionChoice(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc = pUI->getDocument();

	int type = (int)v;
	pDoc->m_nBrushDirection = type;

}
//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas button is pushed
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->clearCanvas();
}

void ImpressionistUI::cb_autodraw_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->autoDraw();
}
//-----------------------------------------------------------
// Updates the brush size to use from the value of the size
// slider
// Called by the UI when the size slider is moved
//-----------------------------------------------------------
void ImpressionistUI::cb_sizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nSize=int( ((Fl_Slider *)o)->value() ) ;
}

void ImpressionistUI::cb_LineWidthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nLineWidth = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_AngleSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nAngle = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_AlphaSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_dAlpha = double(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_SpacingSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nSpacing = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_randattr_button(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data())) ->m_bAttrRand = bool(((Fl_Button *)o)->value());
}

// Background dialog callbacks
void ImpressionistUI::cb_background(Fl_Menu_* o, void* v)
{
	whoami(o)->m_backgroundDialog->show();
}
void ImpressionistUI::cb_background_button(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = (ImpressionistUI*)(o->user_data());
	pUI->m_bBackground = bool(((Fl_Button *)o)->value());
	if (pUI->m_pDoc)
		pUI->m_pDoc->updateBg();
}
void ImpressionistUI::cb_backgroundAlphaSlides(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = (ImpressionistUI*)(o->user_data());
	pUI->m_dBackgroundAlpha = double(((Fl_Slider *)o)->value());
	pUI->setBackground(true);
	if (pUI->m_pDoc)
		pUI->m_pDoc->updateBg();
}

//---------------------------------- per instance functions --------------------------------------

//------------------------------------------------
// Return the ImpressionistDoc used
//------------------------------------------------
ImpressionistDoc* ImpressionistUI::getDocument()
{
	return m_pDoc;
}

//------------------------------------------------
// Draw the main window
//------------------------------------------------
void ImpressionistUI::show() {
	m_mainWindow->show();
	m_paintView->show();
	m_origView->show();
}

//------------------------------------------------
// Change the paint and original window sizes to 
// w by h
//------------------------------------------------
void ImpressionistUI::resize_windows(int w, int h) {
	m_paintView->size(w,h);
	m_origView->size(w,h);
}

//------------------------------------------------ 
// Set the ImpressionistDoc used by the UI to 
// communicate with the brushes 
//------------------------------------------------
void ImpressionistUI::setDocument(ImpressionistDoc* doc)
{
	m_pDoc = doc;

	m_origView->m_pDoc = doc;
	m_paintView->m_pDoc = doc;
}

//------------------------------------------------
// Return the brush size
//------------------------------------------------
int ImpressionistUI::getSize()
{
	return m_nSize;
}
int ImpressionistUI::getLineWidth()
{
	return m_nLineWidth;
}
int ImpressionistUI::getAngle()
{
	return m_nAngle;
}
double ImpressionistUI::getAlpha()
{
	return m_dAlpha;
}
int ImpressionistUI::getSpacing()
{
	return m_nSpacing;
}
bool ImpressionistUI::getAttrRand()
{
	return m_bAttrRand;
}
bool ImpressionistUI::getBackground()
{
	return m_bBackground;
}
double ImpressionistUI::getBackgroundAlpha()
{
	return m_dBackgroundAlpha;
}
//-------------------------------------------------
// Set the brush size
//-------------------------------------------------
void ImpressionistUI::setSize( int size )
{
	if (size < 1) size = 1;
	if (size > 40) size = 40;
	m_nSize=size; 
	m_BrushSizeSlider->value(m_nSize);
}
void ImpressionistUI::setLineWidth(int size)
{
	if (size < 1) size = 1;
	if (size > 40) size = 40;
	m_nLineWidth = size;
	m_LineWidthSlider->value(m_nLineWidth);
}
void ImpressionistUI::setAngle(int angle)
{
	while (angle < 0) angle += 180;
	if (angle > 359) angle = 359;
	m_nAngle = angle;
	m_AngleSlider->value(m_nAngle);
}
void ImpressionistUI::setAlpha(double value)
{
	if (value < 0.0) value = 0.0;
	if (value > 1.0) value = 1.0;

	m_dAlpha = value;
	m_AlphaSlider->value(value);
}
void ImpressionistUI::setSpacing(int size)
{
	if (size < 1) size = 1;
	if (size > 16) size = 16;
	m_nSpacing = size;
	m_SpacingSlider->value(m_nSpacing);
}
void ImpressionistUI::setAttrRand(bool value)
{
	m_bAttrRand = value;
	m_RandAttrButton->value(value);
}
void ImpressionistUI::setBackground(bool value)
{
	m_bBackground = value;
	m_BackgroundButton->value(value);
	if (m_pDoc)
		m_pDoc->updateBg();
}
void ImpressionistUI::setBackgroundAlpha(double value)
{
	if (value < 0.01) value = 0.01;
	if (value > 1.0) value = 1.0;
	m_dBackgroundAlpha = value;
	m_BackgroundAlphaSlider->value(value);
	if (m_pDoc)
		m_pDoc->updateBg();
}
// Main menu definition
Fl_Menu_Item ImpressionistUI::menuitems[] = {
	{ "&File",		0, 0, 0, FL_SUBMENU },
		{ "&Load Image...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load_image },
		{ "&Save Image...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save_image },
		{ "&Brushes...",	FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushes }, 
		{ "&Clear Canvas", FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_clear_canvas, 0, FL_MENU_DIVIDER },
		
		{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
		{ 0 },

	{ "&Edit", 0, 0, 0, FL_SUBMENU },
		{ "&Undo", FL_CTRL + 'z', (Fl_Callback *)ImpressionistUI::cb_undo },
		{ 0 },

	{ "&Display", 0, 0, 0, FL_SUBMENU },
		{ "&Background", 0, (Fl_Callback *)ImpressionistUI::cb_background },
		{ 0 },

	{ "&Help",		0, 0, 0, FL_SUBMENU },
		{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ 0 }
};

// Brush choice menu definition
Fl_Menu_Item ImpressionistUI::brushTypeMenu[NUM_BRUSH_TYPE+1] = {
  {"Points",			FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_POINTS},
  {"Lines",				FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_LINES},
  {"Circles",			FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_CIRCLES},
  {"Scattered Points",	FL_ALT+'q', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_POINTS},
  {"Scattered Lines",	FL_ALT+'m', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_LINES},
  {"Scattered Circles",	FL_ALT+'d', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_CIRCLES},
  {0}
};

// Stroke Direction choice menu definition
Fl_Menu_Item ImpressionistUI::DirectionTypeMenu[NUM_DIRECTION_TYPE + 1] = {
	{ "Slider/Right Mouse", FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)SLIDER_AND_RIGHT_MOUSE },
	{ "Gradient", FL_ALT + 'g', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)GRADIENT },
	{ "Brush Direction", FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)BRUSH_DIRECTION },
	{ 0 }
};

//----------------------------------------------------
// Constructor.  Creates all of the widgets.
// Add new widgets here
//----------------------------------------------------
ImpressionistUI::ImpressionistUI() {
	// Create the main window
	m_mainWindow = new Fl_Window(600, 300, "Impressionist");
		m_mainWindow->user_data((void*)(this));	// record self to be used by static callback functions
		// install menu bar
		m_menubar = new Fl_Menu_Bar(0, 0, 600, 25);
		m_menubar->menu(menuitems);

		// Create a group that will hold two sub windows inside the main
		// window
		Fl_Group* group = new Fl_Group(0, 25, 600, 275);

			// install paint view window
			m_paintView = new PaintView(300, 25, 300, 275, "This is the paint view");//0jon
			m_paintView->box(FL_DOWN_FRAME);

			// install original view window
			m_origView = new OriginalView(0, 25, 300, 275, "This is the orig view");//300jon
			m_origView->box(FL_DOWN_FRAME);
			m_origView->deactivate();

		group->end();
		Fl_Group::current()->resizable(group);
    m_mainWindow->end();

	// init values

	m_nSize = 10;
	m_nLineWidth = 1;
	m_nAngle = 0;
	m_dAlpha = 1.0;
	m_nSpacing = 4;
	m_bAttrRand = false;

	// brush dialog definition
	m_brushDialog = new Fl_Window(400, 325, "Brush Dialog");
		// Add a brush type choice to the dialog
		m_BrushTypeChoice = new Fl_Choice(50,10,150,25,"&Brush");
		m_BrushTypeChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushTypeChoice->menu(brushTypeMenu);
		m_BrushTypeChoice->callback(cb_brushChoice);

		m_StrokeDirectionChoice = new Fl_Choice(120, 40, 150, 25, "&Stroke Direction");
		m_StrokeDirectionChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_StrokeDirectionChoice->menu(DirectionTypeMenu);
		m_StrokeDirectionChoice->callback(cb_StrokeDirectionChoice);

		m_ClearCanvasButton = new Fl_Button(240,10,150,25,"&Clear Canvas");
		m_ClearCanvasButton->user_data((void*)(this));
		m_ClearCanvasButton->callback(cb_clear_canvas_button);

		// Add brush size slider to the dialog 
		m_BrushSizeSlider = new Fl_Value_Slider(10, 80, 300, 25, "Size");
		m_BrushSizeSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushSizeSlider->type(FL_HOR_NICE_SLIDER);
        m_BrushSizeSlider->labelfont(FL_COURIER);
        m_BrushSizeSlider->labelsize(12);
		m_BrushSizeSlider->minimum(1);
		m_BrushSizeSlider->maximum(40);
		m_BrushSizeSlider->step(1);
		m_BrushSizeSlider->value(m_nSize);
		m_BrushSizeSlider->align(FL_ALIGN_RIGHT);
		m_BrushSizeSlider->callback(cb_sizeSlides);

		// Add line width slider to the dialog 
		m_LineWidthSlider = new Fl_Value_Slider(10, 105, 300, 25, "LineWidth");
		m_LineWidthSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_LineWidthSlider->type(FL_HOR_NICE_SLIDER);
		m_LineWidthSlider->labelfont(FL_COURIER);
		m_LineWidthSlider->labelsize(12);
		m_LineWidthSlider->minimum(1);
		m_LineWidthSlider->maximum(40);
		m_LineWidthSlider->step(1);
		m_LineWidthSlider->value(m_nLineWidth);
		m_LineWidthSlider->align(FL_ALIGN_RIGHT);
		m_LineWidthSlider->callback(cb_LineWidthSlides);
		m_LineWidthSlider->deactivate();

		// Add angle slider to the dialog 
		m_AngleSlider = new Fl_Value_Slider(10, 130, 300, 25, "LineAngle");
		m_AngleSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_AngleSlider->type(FL_HOR_NICE_SLIDER);
		m_AngleSlider->labelfont(FL_COURIER);
		m_AngleSlider->labelsize(12);
		m_AngleSlider->minimum(0);
		m_AngleSlider->maximum(359);
		m_AngleSlider->step(1);
		m_AngleSlider->value(m_nAngle);
		m_AngleSlider->align(FL_ALIGN_RIGHT);
		m_AngleSlider->callback(cb_AngleSlides);
		m_AngleSlider->deactivate();

		// Add alpha slider to the dialog
		m_AlphaSlider = new Fl_Value_Slider(10, 155, 300, 25, "Alpha");
		m_AlphaSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_AlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_AlphaSlider->labelfont(FL_COURIER);
		m_AlphaSlider->labelsize(12);
		m_AlphaSlider->minimum(0.0);
		m_AlphaSlider->maximum(1.0);
		m_AlphaSlider->step(0.01);
		m_AlphaSlider->value(m_dAlpha);
		m_AlphaSlider->align(FL_ALIGN_RIGHT);
		m_AlphaSlider->callback(cb_AlphaSlides);
		
		m_SpacingSlider = new Fl_Value_Slider(10, 200, 150, 25, "Spacing");
		m_SpacingSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_SpacingSlider->type(FL_HOR_NICE_SLIDER);
		m_SpacingSlider->labelfont(FL_COURIER);
		m_SpacingSlider->labelsize(12);
		m_SpacingSlider->minimum(1);
		m_SpacingSlider->maximum(16);
		m_SpacingSlider->step(1);
		m_SpacingSlider->value(m_nSpacing);
		m_SpacingSlider->align(FL_ALIGN_RIGHT);
		m_SpacingSlider->callback(cb_SpacingSlides);

		m_RandAttrButton = new Fl_Light_Button(215, 200, 100, 25, "&Attr Rand");
		m_RandAttrButton->user_data((void*)(this));
		m_RandAttrButton->callback(cb_randattr_button);
		m_RandAttrButton->value(m_bAttrRand);

		m_AutoDrawButton = new Fl_Button(320, 200, 50, 25, "&Paint");
		m_AutoDrawButton->user_data((void*)(this));
		m_AutoDrawButton->callback(cb_autodraw_button);

    m_brushDialog->end();	

	m_bBackground = false;
	m_dBackgroundAlpha = 0.4;

	m_backgroundDialog = new Fl_Window(400, 300, "Background Dialog");

		m_BackgroundButton = new Fl_Light_Button(10, 10, 100, 25, "&Show BG");
		m_BackgroundButton->user_data((void*)(this));
		m_BackgroundButton->callback(cb_background_button);
		m_BackgroundButton->value(m_bBackground);

		m_BackgroundAlphaSlider = new Fl_Value_Slider(10, 40, 300, 25, "Alpha");
		m_BackgroundAlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_BackgroundAlphaSlider->labelfont(FL_COURIER);
		m_BackgroundAlphaSlider->labelsize(12);
		m_BackgroundAlphaSlider->minimum(0.01);
		m_BackgroundAlphaSlider->maximum(1.00);
		m_BackgroundAlphaSlider->step(0.01);
		m_BackgroundAlphaSlider->align(FL_ALIGN_RIGHT);
		m_BackgroundAlphaSlider->user_data((void*)(this));
		m_BackgroundAlphaSlider->callback(cb_backgroundAlphaSlides);
		m_BackgroundAlphaSlider->value(m_dBackgroundAlpha);

	m_backgroundDialog->end();
}
