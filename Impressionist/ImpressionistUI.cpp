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
	ImpressionistDoc *pDoc = whoami(o)->getDocument();

	if ((int)v == 1 && !pDoc->m_ucBitmap)
	{
		fl_alert("You must load an image before loading a mural image.");
		return;
	}

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		if ((int)v == 1)
		{
			pDoc->loadImage(newfile, true);
		}
		else
		{
			pDoc->loadImage(newfile, false);
		}
	}
}

void ImpressionistUI::cb_load_another_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();

	if (!pDoc->m_ucBitmap)
	{
		fl_alert("You must load the original image before loading another image.");
		return;
	}

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadAnotherImage(newfile);
	}
}
void ImpressionistUI::cb_load_edge_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();

	if (!pDoc->m_ucBitmap)
	{
		fl_alert("You must load the original image before loading an edge image.");
		return;
	}

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadEdgeImage(newfile);
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
		pDoc->saveImage(newfile, (int)v);
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

void ImpressionistUI::cb_paintly(Fl_Menu_* o, void* v)
{
	whoami(o)->m_paintlyDialog->show();
}
void ImpressionistUI::cb_colorSelector(Fl_Menu_* o, void* v)
{
	whoami(o)->m_colorSelectorDialog->show();
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
	whoami(o)->m_backgroundDialog->hide();
	whoami(o)->m_paintlyDialog->hide();
	whoami(o)->m_colorSelectorDialog->hide();
	whoami(o)->m_FilterDialog->hide();
}

void ImpressionistUI::cb_ChooseDisplay(Fl_Menu_* o, void* v)
{
	whoami(o)->m_pDoc->setDisplayMode((int)v);
}

//-----------------------------------------------------------
// Brings up an about dialog box
// Called by the UI when the about menu item is chosen
//-----------------------------------------------------------
void ImpressionistUI::cb_about(Fl_Menu_* o, void* v) 
{
	fl_message("Authored by glinaa and schenan, Fall 2015. Based on impressionist FLTK version for CS341, Spring 2002");
}

void ImpressionistUI::cb_undo(Fl_Menu_* o, void* v) {
	ImpressionistUI* pUI = whoami(o);
	ImpressionistDoc* pDoc = pUI->getDocument();

	pDoc->undo();
}
void ImpressionistUI::cb_FilterDialogButton(Fl_Widget* o, void* v) {
	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
	pUI->m_FilterDialog->show();
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
void ImpressionistUI::cb_paintlydraw_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->paintlyDraw();
}
//-----------------------------------------------------------
// Updates the brush size to use from the value of the size
// slider
// Called by the UI when the size slider is moved
//-----------------------------------------------------------
void ImpressionistUI::cb_sizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nSize = int(((Fl_Slider *)o)->value());
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
void ImpressionistUI::cb_anothergradient_button(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_bAnotherGradient = bool(((Fl_Button *)o)->value());
}
void ImpressionistUI::cb_edgeclipping_button(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_bEdgeClipping = bool(((Fl_Button *)o)->value());
}
void ImpressionistUI::cb_EdgeThresholdSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nEdgeThreshold = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_EdgeUpdateButton(Fl_Widget* o, void* v)
{
	ImpressionistDoc* pDoc = ((ImpressionistUI*)(o->user_data()))->m_pDoc;
	pDoc->updateEdge();
	pDoc->setDisplayMode(DOC_DISPLAY_EDGE);
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

//paintly dialog callbacks
void ImpressionistUI::cb_ThresholdSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nThreshold = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_CurvatureFilterSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_dCurvatureFilter = double(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_BlurFactorSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_dBlurFactor = double(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_MinStrokeLengthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nMinStrokeLength = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_MaxStrokeLengthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nMaxStrokeLength = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_GridSizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_dGridSize = double(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_PaintlyLevelSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyLevel = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_PaintlyR0Slides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyR0 = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_PaintlyCheckColorButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_bPaintlyCheckColor = bool(((Fl_Button *)o)->value());
}
void ImpressionistUI::cb_PaintlyControlDirButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_bPaintlyControlDir = bool(((Fl_Button *)o)->value());
}
// filter dialog callbacks
void ImpressionistUI::cb_FilterRadiusSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nFilterRadius = int(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_FilterSigmaSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_dFilterSigma = double(((Fl_Slider *)o)->value());
}
void ImpressionistUI::cb_FilterUpdateButton(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = (ImpressionistUI*)(o->user_data());
	if (pUI->m_pDoc)
		pUI->m_pDoc->updateFiltered();
}
void ImpressionistUI::cb_FilterTypeChoose(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = (ImpressionistUI*)(o->user_data());
	if (pUI->m_pDoc)
		pUI->m_pDoc->setFilterType((int)v);
}
void ImpressionistUI::cb_FilterNormalizeKernelButton(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = (ImpressionistUI*)(o->user_data());
	if (pUI->m_pDoc)
		pUI->m_pDoc->normalizeKernel();
}
void ImpressionistUI::cb_FilterOnCurrentButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_bFilterOnCurrent = bool(((Fl_Button *)o)->value());
}
// Alpha brush
void ImpressionistUI::cb_LoadAlphaBrush(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadAlphaBrush(newfile);
	}
}
// Thumbnail
void ImpressionistUI::cb_ThumbnailImage(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();
	pDoc->makeThumbnailImage();
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
bool ImpressionistUI::getAnotherGradient()
{
	return m_bAnotherGradient;
}
bool ImpressionistUI::getEdgeClipping()
{
	return m_bEdgeClipping;
}
bool ImpressionistUI::getBackground()
{
	return m_bBackground;
}
double ImpressionistUI::getBackgroundAlpha()
{
	return m_dBackgroundAlpha;
}
int ImpressionistUI::getEdgeThreshold()
{
	return m_nEdgeThreshold;
}
int	ImpressionistUI::getThreshold()
{
	return m_nThreshold;
}
double ImpressionistUI::getCurvatureFilter()
{
	return m_dCurvatureFilter;
}
double ImpressionistUI::getBlurFactor()
{
	return m_dBlurFactor;
}
int ImpressionistUI::getMinStrokeLength()
{
	return m_nMinStrokeLength;
}
int ImpressionistUI::getMaxStrokeLength()
{
	return m_nMaxStrokeLength;
}
double ImpressionistUI::getGridSize()
{
	return m_dGridSize;
}
int ImpressionistUI::getPaintlyLevel()
{
	return m_nPaintlyLevel;
}
int ImpressionistUI::getPaintlyR0()
{
	return m_nPaintlyR0;
}
bool ImpressionistUI::getPaintlyCheckColor()
{
	return m_bPaintlyCheckColor;
}
bool ImpressionistUI::getPaintlyControlDir()
{
	return m_bPaintlyControlDir;
}
int	ImpressionistUI::getFilterRadius()
{
	return m_nFilterRadius;
}
double ImpressionistUI::getFilterSigma()
{
	return m_dFilterSigma;
}
bool ImpressionistUI::getFilterOnCurrent()
{
	return m_bFilterOnCurrent;
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
void ImpressionistUI::setEdgeThreshold(int value)
{
	if (value > 500) value = 500;
	if (value < 1) value = 1;
	m_nEdgeThreshold = value;
	m_EdgeThresholdSlider->value(value);
}
// Main menu definition
Fl_Menu_Item ImpressionistUI::menuitems[] = {
	{ "&File",		0, 0, 0, FL_SUBMENU },
		{ "&Load Image",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load_image, (void*)0 },
		{ "Load &Mural Image", FL_ALT + 'm', (Fl_Callback *)ImpressionistUI::cb_load_image, (void*)1 },
		{ "Load &Another Image", FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_load_another_image },
		{ "Load &Edge Image", FL_ALT + 'e', (Fl_Callback *)ImpressionistUI::cb_load_edge_image },
		{ "Load Alpha-Mapped Brush", 0, (Fl_Callback *)ImpressionistUI::cb_LoadAlphaBrush, 0, FL_MENU_DIVIDER },
		{ "&Save Image", FL_CTRL + 's', (Fl_Callback *)ImpressionistUI::cb_save_image, (void*)DOC_SAVE_DRAWING },
		{ "Save with Background", 0, (Fl_Callback *)ImpressionistUI::cb_save_image, (void*)DOC_SAVE_DRAWING_WITH_BG },
		{ "Save Edge Image", 0, (Fl_Callback *)ImpressionistUI::cb_save_image, (void*)DOC_SAVE_EDGE },
		{ "Save Filtered Image", 0, (Fl_Callback *)ImpressionistUI::cb_save_image, (void*)DOC_SAVE_FILTERED, FL_MENU_DIVIDER },
		{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
		{ 0 },

	{ "&Edit", 0, 0, 0, FL_SUBMENU },
		{ "&Undo", FL_CTRL + 'z', (Fl_Callback *)ImpressionistUI::cb_undo },
		{ "&Clear Canvas", FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_clear_canvas, 0, FL_MENU_DIVIDER },
		{ "&Brushes", FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushes },
		{ "Colors", FL_ALT + 'k', (Fl_Callback *)ImpressionistUI::cb_colorSelector },
		{ "&Paintly", FL_ALT + 'p', (Fl_Callback *)ImpressionistUI::cb_paintly, 0, FL_MENU_DIVIDER },
		{ "&Background", 0, (Fl_Callback *)ImpressionistUI::cb_background },
		{ "Make Thumbnail", 0, (Fl_Callback *)ImpressionistUI::cb_ThumbnailImage },
		{ 0 },

	{ "&Display", 0, 0, 0, FL_SUBMENU },
		{ "&Original", 0, (Fl_Callback *)ImpressionistUI::cb_ChooseDisplay, (void*)DOC_DISPLAY_ORIGINAL },
		{ "&Filtered", 0, (Fl_Callback *)ImpressionistUI::cb_ChooseDisplay, (void*)DOC_DISPLAY_FILTERED },
		{ "&Edge", 0, (Fl_Callback *)ImpressionistUI::cb_ChooseDisplay, (void*)DOC_DISPLAY_EDGE },
		{ "&Another", 0, (Fl_Callback *)ImpressionistUI::cb_ChooseDisplay, (void*)DOC_DISPLAY_ANOTHER },
		{ "Blurred (for Paintly)", 0, (Fl_Callback *)ImpressionistUI::cb_ChooseDisplay, (void*)DOC_DISPLAY_BLURRED },
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
  {"Curved Brush", FL_ALT + 't', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_CURVED},
  {"Filter Brush", FL_ALT + 'f', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_FILTERED },
  { "Alpha Mapped Brush", FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_ALPHAMAPPED },
  { "Liquify Brush", 0, (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_LIQUIFY },
  {0}
};

// Stroke Direction choice menu definition
Fl_Menu_Item ImpressionistUI::DirectionTypeMenu[NUM_DIRECTION_TYPE + 1] = {
	{ "Slider/Right Mouse", FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)SLIDER_AND_RIGHT_MOUSE },
	{ "Gradient", FL_ALT + 'g', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)GRADIENT },
	{ "Brush Direction", FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_StrokeDirectionChoice, (void *)BRUSH_DIRECTION },
	{ 0 }
};

Fl_Menu_Item ImpressionistUI::filterTypeMenu[NUM_FILTER_TYPE + 1] = {
	{ "Gaussian Filter", 0, (Fl_Callback *)ImpressionistUI::cb_FilterTypeChoose, (void *)FB_GAUSSIAN_FILTER },
	{ "Mean Filter", 0, (Fl_Callback *)ImpressionistUI::cb_FilterTypeChoose, (void *)FB_MEAN_FILTER },
	{ "Median Filter", 0, (Fl_Callback *)ImpressionistUI::cb_FilterTypeChoose, (void *)FB_MEDIAN_FILTER },
	{ "Custom Filter", 0, (Fl_Callback *)ImpressionistUI::cb_FilterTypeChoose, (void *)FB_CUSTOM_FILTER },
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
	m_nEdgeThreshold = 200;
	m_bAnotherGradient = false;
	m_bEdgeClipping = false;

	m_nThreshold = 50;
	m_dCurvatureFilter = 1.0;
	m_dBlurFactor = 0.25;
	m_nMinStrokeLength = 4;
	m_nMaxStrokeLength = 16;
	m_dGridSize = 1.0;

	m_nPaintlyLevel = 3;
	m_nPaintlyR0 = 3;
	m_bPaintlyControlDir = false;
	m_bPaintlyCheckColor = true;

	m_nFilterRadius = 2;
	m_dFilterSigma = 1.0;
	m_bFilterOnCurrent = false;
	static const char* filterDefaultKernel = "5 5\n1 2 3 2 1\n0.5 1 2 1 0.5\n0 0 0 0 0\n-0.5 -1 -2 -1 -0.5\n-1 -2 -3 -2 -1";

	// brush dialog definition
	m_brushDialog = new Fl_Window(410, 325, "Brush Dialog");
		// Add a brush type choice to the dialog
		m_BrushTypeChoice = new Fl_Choice(50,10,213,25,"&Brush");
		m_BrushTypeChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushTypeChoice->menu(brushTypeMenu);
		m_BrushTypeChoice->callback(cb_brushChoice);

		m_StrokeDirectionChoice = new Fl_Choice(113, 40, 150, 25, "Stroke Direction");
		m_StrokeDirectionChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_StrokeDirectionChoice->menu(DirectionTypeMenu);
		m_StrokeDirectionChoice->callback(cb_StrokeDirectionChoice);

		m_ClearCanvasButton = new Fl_Button(275,10,115,25,"&Clear Canvas");
		m_ClearCanvasButton->user_data((void*)(this));
		m_ClearCanvasButton->callback(cb_clear_canvas_button);

		m_FilterDialogButton = new Fl_Button(275, 40, 115, 25, "Edit Filter");
		m_FilterDialogButton->user_data((void*)(this));
		m_FilterDialogButton->callback(cb_FilterDialogButton);

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

		m_RandAttrButton = new Fl_Light_Button(223, 200, 95, 25, "Attr Rand");
		m_RandAttrButton->user_data((void*)(this));
		m_RandAttrButton->callback(cb_randattr_button);
		m_RandAttrButton->value(m_bAttrRand);

		m_AutoDrawButton = new Fl_Button(330, 200, 60, 25, "Paint");
		m_AutoDrawButton->user_data((void*)(this));
		m_AutoDrawButton->callback(cb_autodraw_button);

		m_EdgeThresholdSlider = new Fl_Value_Slider(10, 235, 270, 25, "Edge T");
		m_EdgeThresholdSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_EdgeThresholdSlider->type(FL_HOR_NICE_SLIDER);
		m_EdgeThresholdSlider->labelfont(FL_COURIER);
		m_EdgeThresholdSlider->labelsize(12);
		m_EdgeThresholdSlider->minimum(1);
		m_EdgeThresholdSlider->maximum(500);
		m_EdgeThresholdSlider->step(1);
		m_EdgeThresholdSlider->value(m_nEdgeThreshold);
		m_EdgeThresholdSlider->align(FL_ALIGN_RIGHT);
		m_EdgeThresholdSlider->callback(cb_EdgeThresholdSlides);

		m_EdgeUpdateButton = new Fl_Button(330, 235, 60, 25, "Update");
		m_EdgeUpdateButton->user_data((void*)(this));
		m_EdgeUpdateButton->callback(cb_EdgeUpdateButton);

		m_AnotherGradientButton = new Fl_Light_Button(10, 270, 184, 25, "Another Gradient");
		m_AnotherGradientButton->user_data((void*)(this));
		m_AnotherGradientButton->callback(cb_anothergradient_button);
		m_AnotherGradientButton->value(m_bAnotherGradient);

		m_EdgeClippingButton = new Fl_Light_Button(206, 270, 184, 25, "Edge Clipping");
		m_EdgeClippingButton->user_data((void*)(this));
		m_EdgeClippingButton->callback(cb_edgeclipping_button);
		m_EdgeClippingButton->value(m_bEdgeClipping);
    m_brushDialog->end();	

	m_FilterDialog = new Fl_Window(380, 300, "Filter");

		m_FilterChoice = new Fl_Choice(82, 10, 150, 25, "&Filter Type");
		m_FilterChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_FilterChoice->menu(filterTypeMenu);
		m_FilterChoice->callback(cb_FilterTypeChoose);

		m_FilterUpdateButton = new Fl_Button(242, 10, 118, 25, "Update");
		m_FilterUpdateButton->user_data((void*)(this));
		m_FilterUpdateButton->callback(cb_FilterUpdateButton);

		m_FilterRadiusSlider = new Fl_Value_Slider(10, 45, 300, 25, "Radius");
		m_FilterRadiusSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_FilterRadiusSlider->type(FL_HOR_NICE_SLIDER);
		m_FilterRadiusSlider->labelfont(FL_COURIER);
		m_FilterRadiusSlider->labelsize(12);
		m_FilterRadiusSlider->minimum(0);
		m_FilterRadiusSlider->maximum(10);
		m_FilterRadiusSlider->step(1);
		m_FilterRadiusSlider->value(m_nFilterRadius);
		m_FilterRadiusSlider->align(FL_ALIGN_RIGHT);
		m_FilterRadiusSlider->callback(cb_FilterRadiusSlides);

		m_FilterRadiusSlider = new Fl_Value_Slider(10, 80, 300, 25, "Sigma");
		m_FilterRadiusSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_FilterRadiusSlider->type(FL_HOR_NICE_SLIDER);
		m_FilterRadiusSlider->labelfont(FL_COURIER);
		m_FilterRadiusSlider->labelsize(12);
		m_FilterRadiusSlider->minimum(0.0);
		m_FilterRadiusSlider->maximum(10.0);
		m_FilterRadiusSlider->step(0.05);
		m_FilterRadiusSlider->value(m_dFilterSigma);
		m_FilterRadiusSlider->align(FL_ALIGN_RIGHT);
		m_FilterRadiusSlider->callback(cb_FilterSigmaSlides);

		m_FilterKernelInput = new Fl_Multiline_Input(10, 115, 300, 100, "Kernel");
		m_FilterKernelInput->user_data((void*)(this));
		m_FilterKernelInput->labelfont(FL_COURIER);
		m_FilterKernelInput->labelsize(12);
		m_FilterKernelInput->align(FL_ALIGN_RIGHT);
		m_FilterKernelInput->value(filterDefaultKernel);

		m_FilterNormalizeKernelButton = new Fl_Button(10, 225, 120, 25, "Normalize");
		m_FilterNormalizeKernelButton->user_data((void*)(this));
		m_FilterNormalizeKernelButton->callback(cb_FilterNormalizeKernelButton);

		m_FilterOnCurrentButton = new Fl_Light_Button(140, 225, 120, 25, "On Current");
		m_FilterOnCurrentButton->user_data((void*)(this));
		m_FilterOnCurrentButton->value(m_bFilterOnCurrent);
		m_FilterOnCurrentButton->callback(cb_FilterOnCurrentButton);

	m_FilterDialog->end();

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

	m_paintlyDialog = new Fl_Window(430, 350, "Paintly Dialog");

		m_pAutoDrawButton = new Fl_Button(10, 20, 50, 25, "Paint");
		m_pAutoDrawButton->user_data((void*)(this));
		m_pAutoDrawButton->callback(cb_paintlydraw_button);

		m_PaintlyCheckColorButton = new Fl_Light_Button(70, 20, 100, 25, "Chk Color");
		m_PaintlyCheckColorButton->user_data((void*)(this));
		m_PaintlyCheckColorButton->callback(cb_PaintlyCheckColorButton);
		m_PaintlyCheckColorButton->value(m_bPaintlyCheckColor);

		m_PaintlyControlDirButton = new Fl_Light_Button(180, 20, 100, 25, "Ctrl Dir");
		m_PaintlyControlDirButton->user_data((void*)(this));
		m_PaintlyControlDirButton->callback(cb_PaintlyControlDirButton);
		m_PaintlyControlDirButton->value(m_bPaintlyControlDir);

		m_pAlphaSlider = new Fl_Value_Slider(10, 50, 300, 25, "Alpha");
		m_pAlphaSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_pAlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_pAlphaSlider->labelfont(FL_COURIER);
		m_pAlphaSlider->labelsize(12);
		m_pAlphaSlider->minimum(0.0);
		m_pAlphaSlider->maximum(1.0);
		m_pAlphaSlider->step(0.01);
		m_pAlphaSlider->value(m_dAlpha);
		m_pAlphaSlider->align(FL_ALIGN_RIGHT);
		m_pAlphaSlider->callback(cb_AlphaSlides);

		m_ThresholdSlider = new Fl_Value_Slider(10, 80, 300, 25, "Threshold");
		m_ThresholdSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_ThresholdSlider->type(FL_HOR_NICE_SLIDER);
		m_ThresholdSlider->labelfont(FL_COURIER);
		m_ThresholdSlider->labelsize(12);
		m_ThresholdSlider->minimum(0);
		m_ThresholdSlider->maximum(250);
		m_ThresholdSlider->step(1);
		m_ThresholdSlider->value(m_nThreshold);
		m_ThresholdSlider->align(FL_ALIGN_RIGHT);
		m_ThresholdSlider->callback(cb_ThresholdSlides);

		m_CurvatureFilterSlider = new Fl_Value_Slider(10, 110, 300, 25, "Curvature");
		m_CurvatureFilterSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_CurvatureFilterSlider->type(FL_HOR_NICE_SLIDER);
		m_CurvatureFilterSlider->labelfont(FL_COURIER);
		m_CurvatureFilterSlider->labelsize(12);
		m_CurvatureFilterSlider->minimum(0.0);
		m_CurvatureFilterSlider->maximum(1.0);
		m_CurvatureFilterSlider->step(0.01);
		m_CurvatureFilterSlider->value(m_dCurvatureFilter);
		m_CurvatureFilterSlider->align(FL_ALIGN_RIGHT);
		m_CurvatureFilterSlider->callback(cb_CurvatureFilterSlides);

		m_BlurFactorSlider = new Fl_Value_Slider(10, 140, 300, 25, "Blur");
		m_BlurFactorSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_BlurFactorSlider->type(FL_HOR_NICE_SLIDER);
		m_BlurFactorSlider->labelfont(FL_COURIER);
		m_BlurFactorSlider->labelsize(12);
		m_BlurFactorSlider->minimum(0.0);
		m_BlurFactorSlider->maximum(1.0);
		m_BlurFactorSlider->step(0.05);
		m_BlurFactorSlider->value(m_dBlurFactor);
		m_BlurFactorSlider->align(FL_ALIGN_RIGHT);
		m_BlurFactorSlider->callback(cb_BlurFactorSlides);

		m_MinStrokeLengthSlider = new Fl_Value_Slider(10, 170, 300, 25, "MinStrokeLength");
		m_MinStrokeLengthSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_MinStrokeLengthSlider->type(FL_HOR_NICE_SLIDER);
		m_MinStrokeLengthSlider->labelfont(FL_COURIER);
		m_MinStrokeLengthSlider->labelsize(12);
		m_MinStrokeLengthSlider->minimum(0);
		m_MinStrokeLengthSlider->maximum(30);
		m_MinStrokeLengthSlider->step(1);
		m_MinStrokeLengthSlider->value(m_nMinStrokeLength);
		m_MinStrokeLengthSlider->align(FL_ALIGN_RIGHT);
		m_MinStrokeLengthSlider->callback(cb_MinStrokeLengthSlides);

		m_MaxStrokeLengthSlider = new Fl_Value_Slider(10, 200, 300, 25, "MaxStrokeLength");
		m_MaxStrokeLengthSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_MaxStrokeLengthSlider->type(FL_HOR_NICE_SLIDER);
		m_MaxStrokeLengthSlider->labelfont(FL_COURIER);
		m_MaxStrokeLengthSlider->labelsize(12);
		m_MaxStrokeLengthSlider->minimum(0);
		m_MaxStrokeLengthSlider->maximum(30);
		m_MaxStrokeLengthSlider->step(1);
		m_MaxStrokeLengthSlider->value(m_nMaxStrokeLength);
		m_MaxStrokeLengthSlider->align(FL_ALIGN_RIGHT);
		m_MaxStrokeLengthSlider->callback(cb_MaxStrokeLengthSlides);

		m_GridSizeSlider = new Fl_Value_Slider(10, 230, 300, 25, "Grid Size");
		m_GridSizeSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_GridSizeSlider->type(FL_HOR_NICE_SLIDER);
		m_GridSizeSlider->labelfont(FL_COURIER);
		m_GridSizeSlider->labelsize(12);
		m_GridSizeSlider->minimum(0.0);
		m_GridSizeSlider->maximum(1.0);
		m_GridSizeSlider->step(0.01);
		m_GridSizeSlider->value(m_dGridSize);
		m_GridSizeSlider->align(FL_ALIGN_RIGHT);
		m_GridSizeSlider->callback(cb_GridSizeSlides);

		m_PaintlyLevelSlider = new Fl_Value_Slider(10, 260, 300, 25, "Levels");
		m_PaintlyLevelSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_PaintlyLevelSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyLevelSlider->labelfont(FL_COURIER);
		m_PaintlyLevelSlider->labelsize(12);
		m_PaintlyLevelSlider->minimum(1);
		m_PaintlyLevelSlider->maximum(5);
		m_PaintlyLevelSlider->step(1);
		m_PaintlyLevelSlider->value(m_nPaintlyLevel);
		m_PaintlyLevelSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyLevelSlider->callback(cb_PaintlyLevelSlides);

		m_PaintlyR0Slider = new Fl_Value_Slider(10, 290, 300, 25, "R0");
		m_PaintlyR0Slider->user_data((void*)(this));	// record self to be used by static callback functions
		m_PaintlyR0Slider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyR0Slider->labelfont(FL_COURIER);
		m_PaintlyR0Slider->labelsize(12);
		m_PaintlyR0Slider->minimum(1);
		m_PaintlyR0Slider->maximum(5);
		m_PaintlyR0Slider->step(1);
		m_PaintlyR0Slider->value(m_nPaintlyR0);
		m_PaintlyR0Slider->align(FL_ALIGN_RIGHT);
		m_PaintlyR0Slider->callback(cb_PaintlyR0Slides);

	m_backgroundDialog->end();

	m_colorSelectorDialog = new Fl_Window(420, 210, "Color Selector");
		m_colorSelector = new Fl_Color_Chooser(10, 10, 400, 190);
		m_colorSelector->rgb(1.0, 1.0, 1.0);
	m_colorSelectorDialog->end();
}
