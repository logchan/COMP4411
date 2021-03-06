// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"
#include <list>

enum DocDisplayMode {
	DOC_DISPLAY_ORIGINAL,
	DOC_DISPLAY_EDGE,
	DOC_DISPLAY_ANOTHER,
	DOC_DISPLAY_BLURRED,
	DOC_DISPLAY_FILTERED
};

enum DocSaveImageType {
	DOC_SAVE_DRAWING,
	DOC_SAVE_DRAWING_WITH_BG,
	DOC_SAVE_EDGE,
	DOC_SAVE_FILTERED
};

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname, bool isMural);			// called by the UI to load image
	int		loadAnotherImage(char *iname);
	int		loadEdgeImage(char *iname);
	int		saveImage(char *iname, int type);			// called by the UI to save image


	int     clearCanvas();                  // called by the UI to clear the drawing canvas
	void	setBrushType(int type);			// called by the UI to set the brushType
	int		getSize();						// get the UI size
	int		getLineWidth();
	int		getAngle();
	double  getAlpha();
	void	setSize(int size);				// set the UI size
	void	setLineWidth(int size);
	void	setAngle(int angle);
	char*	getImageName();					// get the current image name
	int getDisplayMode();
	void setDisplayMode(int mode);

	int		autoDraw();
	int 	paintlyDraw();

	void undo();
	void pushToUndo();

	void updateBg();

	void updateEdge();

	void updateFiltered();
	void setFilterType(int type);
	void normalizeKernel();

	int loadAlphaBrush(char* iname);
	void makeThumbnailImage();

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting.
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;
	unsigned char*  m_ucPreservedPainting;
	unsigned char*  m_ucEdgeBitmap;
	unsigned char*	m_ucBitmapBlurred;
	unsigned char*  m_ucBitmapFiltered;

	int  m_nAlphaBrushWidth;
	int  m_nAlphaBrushHeight;
	unsigned char*  m_ucAlphaBrush;

	int* m_iGradient;
	int* m_iGradientMagnitude;

	unsigned char*	m_ucAnotherBitmap;
	int* m_iAnotherGradient;

	// Undo
	std::list<unsigned char*> m_lUndoList;
	bool m_bHasPendingUndo;

	// Background
	bool m_bHasPendingBgUpdate;

	// The current active brush.
	ImpBrush*			m_pCurrentBrush;

	// current brush direction
	int m_nBrushDirection;

	// Size of the brush.
	int m_nSize;							
	int m_nLineWidth;
	int m_nAngle;
	ImpressionistUI*	m_pUI;

	// Paintly
	bool m_bIsPaintlyBegin;
	int m_nPaintlySize;

	// Filter
	int m_nFilterType;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );  
	GLubyte* GetFilteredPixel(int x, int y);

private:
	char			m_imageName[256];
	int m_nDisplayMode;
};

extern void MessageBox(char *message);

#endif
