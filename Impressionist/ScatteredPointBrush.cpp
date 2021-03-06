//
// ScatteredPointBrush.cpp
//
// The implementation of Scattered Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "Scatteredpointbrush.h"

extern float frand();
extern int irand(int);

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}

	glPointSize(1);

	glBegin(GL_POINTS);
	int loop_time = pDoc->getSize()*4;
	for (int i = 0; i < loop_time; ++i)
	{
		int Xoffset = irand(pDoc->getSize()) - pDoc->getSize() / 2;
		int Yoffset = irand(pDoc->getSize()) - pDoc->getSize() / 2;
		SetColor(source.x + Xoffset, source.y + Yoffset);
		glVertex2d(target.x + Xoffset, target.y + Yoffset);
	}
	glEnd();
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}
