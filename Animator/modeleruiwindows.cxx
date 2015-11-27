// generated by Fast Light User Interface Designer (fluid) version 1.00

#include "modeleruiwindows.h"

Fl_Menu_Item ModelerUIWindows::menu_m_pmbMenuBar[] = {
 {"&File", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&Open Animation Script...", 0,  0, 0, 0, 0, 0, 14, 0},
 {"&Save Animation Script As...", 0,  0, 0, 128, 0, 0, 14, 0},
 {"S&ave Current Frame As...", 0,  0, 0, 128, 0, 0, 14, 0},
 {"Sa&ve Movie As...", 0,  0, 0, 128, 0, 0, 14, 0},
 {"E&xit", 0,  0, 0, 0, 0, 0, 14, 0},
 {0},
 {"&View", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&Normal", 0,  0, 0, 12, 0, 0, 14, 0},
 {"&Flat Shaded", 0,  0, 0, 8, 0, 0, 14, 0},
 {"&Wireframe", 0,  0, 0, 136, 0, 0, 14, 0},
 {"&High Quality", 0,  0, 0, 8, 0, 0, 14, 0},
 {"&Medium Quality", 0,  0, 0, 12, 0, 0, 14, 0},
 {"&Low Quality", 0,  0, 0, 8, 0, 0, 14, 0},
 {"&Poor Quality", 0,  0, 0, 8, 0, 0, 14, 0},
 {0},
 {"&Animation", 0,  0, 0, 64, 0, 0, 14, 0},
 {"&Set Animation Length", 0,  0, 0, 0, 0, 0, 14, 0},
 {0},
 {0}
};
Fl_Menu_Item* ModelerUIWindows::m_pmiOpenAniScript = ModelerUIWindows::menu_m_pmbMenuBar + 1;
Fl_Menu_Item* ModelerUIWindows::m_pmiSaveAniScript = ModelerUIWindows::menu_m_pmbMenuBar + 2;
Fl_Menu_Item* ModelerUIWindows::m_pmiSaveBitmapFile = ModelerUIWindows::menu_m_pmbMenuBar + 3;
Fl_Menu_Item* ModelerUIWindows::m_pmiSaveMovie = ModelerUIWindows::menu_m_pmbMenuBar + 4;
Fl_Menu_Item* ModelerUIWindows::m_pmiExit = ModelerUIWindows::menu_m_pmbMenuBar + 5;
Fl_Menu_Item* ModelerUIWindows::m_pmiNormal = ModelerUIWindows::menu_m_pmbMenuBar + 8;
Fl_Menu_Item* ModelerUIWindows::m_pmiFlatShaded = ModelerUIWindows::menu_m_pmbMenuBar + 9;
Fl_Menu_Item* ModelerUIWindows::m_pmiWireFrame = ModelerUIWindows::menu_m_pmbMenuBar + 10;
Fl_Menu_Item* ModelerUIWindows::m_pmiHightQuality = ModelerUIWindows::menu_m_pmbMenuBar + 11;
Fl_Menu_Item* ModelerUIWindows::m_pmiMediumQuality = ModelerUIWindows::menu_m_pmbMenuBar + 12;
Fl_Menu_Item* ModelerUIWindows::m_pmiLowQuality = ModelerUIWindows::menu_m_pmbMenuBar + 13;
Fl_Menu_Item* ModelerUIWindows::m_pmiPoorQuality = ModelerUIWindows::menu_m_pmbMenuBar + 14;
Fl_Menu_Item* ModelerUIWindows::m_pmiSetAniLen = ModelerUIWindows::menu_m_pmbMenuBar + 17;

Fl_Menu_Item ModelerUIWindows::menu_m_pchoCurveType[] = {
 {"Linear", 0,  0, 0, 0, 0, 0, 12, 0},
 {"B-Spline", 0,  0, 0, 0, 0, 0, 12, 0},
 {"Bezier", 0,  0, 0, 0, 0, 0, 12, 0},
 {"Catmull-Rom", 0,  0, 0, 0, 0, 0, 12, 0},
 {"C2-Interpolating", 0,  0, 0, 0, 0, 0, 12, 0},
 {"SubDivision", 0,  0, 0, 0, 0, 0, 12, 0},
 {0}
};

Fl_Menu_Item ModelerUIWindows::menu_m_pchoShading[] = {
 {"Default", 0,  0, 0, 0, 0, 0, 12, 0},
 {"Phong", 0,  0, 0, 4, 0, 0, 12, 0},
 {"Cel", 0,  0, 0, 4, 0, 0, 12, 0},
 {"Proj Texture", 0,  0, 0, 0, 0, 0, 12, 0},
 {0}
};

ModelerUIWindows::ModelerUIWindows() {
  Fl_Window* w;
  { Fl_Window* o = m_pwndMainWnd = new Fl_Window(832, 754, "CS 341 Animator (Sp02)");
    w = o;
    o->color(185);
    o->labeltype(FL_NORMAL_LABEL);
    o->user_data((void*)(this));
    o->when(FL_WHEN_NEVER);
    { Fl_Menu_Bar* o = m_pmbMenuBar = new Fl_Menu_Bar(0, 0, 840, 25);
      o->selection_color(137);
      o->labelsize(12);
      o->textsize(12);
      o->menu(menu_m_pmbMenuBar);
    }
    { Fl_Browser* o = m_pbrsBrowser = new Fl_Browser(5, 55, 145, 485);
      o->type(3);
      o->selection_color(29);
      o->labeltype(FL_NO_LABEL);
      o->textsize(10);
      o->user_data((void*)(this));
    }
    { Fl_Tabs* o = m_ptabTab = new Fl_Tabs(155, 30, 685, 575);
      o->color(185);
      o->user_data((void*)(this));
      o->align(FL_ALIGN_CENTER);
      { Fl_Scroll* o = m_pscrlScroll = new Fl_Scroll(155, 50, 430, 490, "Modeler");
        o->type(6);
        o->labelsize(12);
        o->when(FL_WHEN_CHANGED);
        o->hide();
        { Fl_Pack* o = m_ppckPack = new Fl_Pack(155, 50, 290, 490);
          o->end();
          Fl_Group::current()->resizable(o);
        }
        o->end();
        Fl_Group::current()->resizable(o);
      }
      { Fl_Group* o = m_pgrpCurveGroup = new Fl_Group(160, 55, 665, 545, "Curves");
        o->labelsize(12);
        { Fl_Group* o = new Fl_Group(160, 55, 420, 410);
          { Fl_Box* o = new Fl_Box(160, 55, 40, 20, "Useless Box");
            o->box(FL_ENGRAVED_BOX);
            o->labeltype(FL_NO_LABEL);
          }
          { RulerWindow* o = m_pwndHRuler = new RulerWindow(205, 55, 375, 20);
            o->box(FL_ENGRAVED_BOX);
            o->end();
          }
          { RulerWindow* o = m_pwndVRuler = new RulerWindow(160, 80, 40, 385);
            o->box(FL_ENGRAVED_BOX);
            m_pwndVRuler->type(RW_VERTICAL);
            o->end();
          }
          { GraphWidget* o = m_pwndGraphWidget = new GraphWidget(205, 80, 375, 385);
            o->box(FL_ENGRAVED_BOX);
            o->user_data((void*)(this));
            o->end();
            Fl_Group::current()->resizable(o);
          }
          { Fl_Group* o = new Fl_Group(185, 80, 395, 385);
            o->end();
          }
          o->end();
          Fl_Group::current()->resizable(o);
        }
        { Fl_Group* o = new Fl_Group(160, 470, 420, 130);
          { Fl_Box* o = new Fl_Box(160, 470, 75, 20, "Curve Type:");
            o->labelsize(12);
            o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
          }
          { Fl_Choice* o = m_pchoCurveType = new Fl_Choice(230, 470, 115, 20);
            o->labeltype(FL_NO_LABEL);
            o->labelsize(12);
            o->textsize(12);
            o->user_data((void*)(this));
            o->menu(menu_m_pchoCurveType);
          }
          { Fl_Light_Button* o = m_pbtWrap = new Fl_Light_Button(345, 470, 70, 20, "Wrap");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          { Fl_Button* o = m_pbtZoomAll = new Fl_Button(505, 470, 75, 20, "Z&oom All");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          { Fl_Value_Slider* o = m_pflatnessSlider = new Fl_Value_Slider(230, 495, 185, 20, "Flatness:");
            o->type(1);
            o->labelsize(12);
            o->minimum(0.001);
            o->maximum(0.2);
            o->step(0.001);
            o->value(0.01);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_LEFT);
          }
          { Fl_Value_Slider* o = m_ptensionSlider = new Fl_Value_Slider(230, 520, 185, 20, "Tension:");
            o->type(1);
            o->labelsize(12);
            o->minimum(0.1);
            o->maximum(2.5);
            o->step(0.1);
            o->value(0.5);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_LEFT);
          }
          { Fl_Light_Button* o = m_pbtAdaptive = new Fl_Light_Button(420, 470, 80, 20, "Apdative");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          { Fl_Input* o = averageMask = new Fl_Input(230, 570, 185, 25, "AverageMask:");
            o->labelsize(10);
            o->textsize(10);
            o->user_data((void*)(this));
          }
          { Fl_Value_Slider* o = m_pDepthSlider = new Fl_Value_Slider(230, 545, 185, 20, "Depth:");
            o->type(1);
            o->labelsize(12);
            o->maximum(10);
            o->step(1);
            o->value(1);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_LEFT);
          }
          { Fl_Light_Button* o = m_pbtBSsurface = new Fl_Light_Button(420, 495, 80, 20, "BSsurface");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(420, 535, 160, 65, "C2 Points");
          o->labelfont(1);
          o->labelsize(12);
          o->align(FL_ALIGN_TOP_LEFT);
          { Fl_Value_Input* o = m_pC2X1ValueInput = new Fl_Value_Input(445, 540, 30, 25, "X1");
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->textsize(12);
          }
          { Fl_Value_Input* o = m_pC2Y1ValueInput = new Fl_Value_Input(495, 540, 30, 25, "Y1");
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->textsize(12);
          }
          { Fl_Value_Input* o = m_pC2X2ValueInput = new Fl_Value_Input(445, 570, 30, 25, "X2");
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->textsize(12);
          }
          { Fl_Value_Input* o = m_pC2Y2ValueInput = new Fl_Value_Input(495, 570, 30, 25, "Y2");
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->textsize(12);
          }
          { Fl_Button* o = m_pbApplyC2Points = new Fl_Button(530, 540, 50, 55, "Apply");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          o->end();
        }
        { Fl_Light_Button* o = m_pbtReadBSSfile = new Fl_Light_Button(505, 495, 75, 20, "ReadFile");
          o->labelsize(12);
          o->user_data((void*)(this));
        }
        { Fl_Group* o = new Fl_Group(585, 55, 240, 135, "Render Option");
          o->labelfont(1);
          o->labelsize(12);
          o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
          { Fl_Choice* o = m_pchoShading = new Fl_Choice(635, 80, 110, 20, "Shader:");
            o->labelsize(12);
            o->textsize(12);
            o->user_data((void*)(this));
            o->menu(menu_m_pchoShading);
          }
          { Fl_Light_Button* o = m_pbtnTeapot = new Fl_Light_Button(745, 80, 75, 20, "Teapot");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          o->end();
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(175, 55, 665, 550, "Texture");
        o->labelsize(12);
        o->hide();
        { Fl_Group* o = new Fl_Group(175, 80, 75, 250, "Position");
          o->labelsize(12);
          o->align(FL_ALIGN_BOTTOM);
          { Fl_Slider* o = m_projTextPosZ = new Fl_Slider(225, 80, 25, 250, "Z");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->value(4);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Slider* o = m_projTextPosX = new Fl_Slider(175, 80, 25, 250, "X");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->value(4);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Slider* o = m_projTextPosY = new Fl_Slider(200, 80, 25, 250, "Y");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(0);
            o->step(0.1);
            o->value(-4);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          o->end();
        }
        { Fl_Group* o = new Fl_Group(275, 80, 75, 250, "Look At");
          o->labelsize(12);
          o->align(FL_ALIGN_BOTTOM);
          { Fl_Slider* o = m_projTextAtZ = new Fl_Slider(325, 80, 25, 250, "Z");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Slider* o = m_projTextAtX = new Fl_Slider(275, 80, 25, 250, "X");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(10);
            o->step(0.1);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Slider* o = m_projTextAtY = new Fl_Slider(300, 80, 25, 250, "Y");
            o->type(4);
            o->labelsize(12);
            o->minimum(-10);
            o->maximum(0);
            o->step(0.1);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_TOP);
          }
          o->end();
        }
        o->end();
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(5, 605, 835, 200, "Animation Controls");
      o->labeltype(FL_NO_LABEL);
      { Fl_Group* o = new Fl_Group(155, 605, 685, 145, "Playback");
        o->labeltype(FL_NO_LABEL);
        { Fl_Group* o = new Fl_Group(155, 605, 685, 55, "Playback Controls");
          o->box(FL_ENGRAVED_BOX);
          o->labeltype(FL_NO_LABEL);
          { Fl_Button* o = m_pbtStepBack = new Fl_Button(165, 635, 20, 20, "@|<");
            o->shortcut(0x7a);
            o->labeltype(FL_SYMBOL_LABEL);
            o->user_data((void*)(this));
          }
          { Fl_Button* o = m_pbtPlay = new Fl_Button(185, 635, 40, 20, "@>");
            o->shortcut(0x78);
            o->labeltype(FL_SYMBOL_LABEL);
            o->user_data((void*)(this));
          }
          { Fl_Button* o = m_pbtStepForw = new Fl_Button(225, 635, 20, 20, "@>|");
            o->shortcut(0x63);
            o->labeltype(FL_SYMBOL_LABEL);
            o->user_data((void*)(this));
          }
          { Fl_Light_Button* o = m_pbtLoop = new Fl_Light_Button(250, 635, 50, 20, "&Loop");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          { Fl_Light_Button* o = m_pbtSimulate = new Fl_Light_Button(335, 635, 70, 20, "&Simulate");
            o->labelsize(12);
            o->user_data((void*)(this));
          }
          { Fl_Value_Slider* o = m_psldrFPS = new Fl_Value_Slider(470, 635, 100, 20, "FPS");
            o->type(5);
            o->labelsize(12);
            o->minimum(5);
            o->maximum(30);
            o->step(1);
            o->value(30);
            o->user_data((void*)(this));
            o->align(FL_ALIGN_LEFT);
            Fl_Group::current()->resizable(o);
          }
          { Fl_Box* o = new Fl_Box(165, 610, 135, 20, "Playback Controls");
            o->labelsize(12);
            o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
          }
          o->end();
        }
        { IndicatorWindow* o = m_pwndIndicatorWnd = new IndicatorWindow(265, 665, 555, 20);
          o->box(FL_ENGRAVED_BOX);
          o->user_data((void*)(this));
          o->align(FL_ALIGN_LEFT);
          o->when(FL_WHEN_RELEASE_ALWAYS);
          o->end();
          Fl_Group::current()->resizable(o);
        }
        { Fl_Slider* o = m_psldrTimeSlider = new Fl_Slider(260, 685, 560, 20);
          o->type(5);
          o->user_data((void*)(this));
        }
        { Fl_Slider* o = m_psldrPlayStart = new Fl_Slider(260, 705, 560, 20);
          o->type(5);
          o->color(10);
          o->user_data((void*)(this));
        }
        { Fl_Slider* o = m_psldrPlayEnd = new Fl_Slider(260, 725, 560, 20);
          o->type(5);
          o->color(80);
          o->user_data((void*)(this));
        }
        { Fl_Box* o = new Fl_Box(155, 685, 90, 20, "Time:");
          o->labelsize(12);
          o->labelcolor(7);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = new Fl_Box(155, 705, 90, 20, "Start:");
          o->labelsize(12);
          o->labelcolor(7);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = new Fl_Box(155, 725, 90, 20, "End:");
          o->labelsize(12);
          o->labelcolor(7);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Output* o = m_poutTime = new Fl_Output(205, 685, 55, 20, "Time:");
          o->labeltype(FL_NO_LABEL);
          o->labelsize(12);
          o->textsize(12);
        }
        { Fl_Output* o = m_poutPlayStart = new Fl_Output(205, 705, 55, 20, "Time:");
          o->labeltype(FL_NO_LABEL);
          o->labelsize(12);
          o->textsize(12);
        }
        { Fl_Output* o = m_poutPlayEnd = new Fl_Output(205, 725, 55, 20, "Time:");
          o->labeltype(FL_NO_LABEL);
          o->labelsize(12);
          o->textsize(12);
        }
        o->end();
        Fl_Group::current()->resizable(o);
      }
      { Fl_Group* o = new Fl_Group(5, 645, 145, 105, "Camera");
        o->box(FL_ENGRAVED_BOX);
        o->labeltype(FL_NO_LABEL);
        { Fl_Box* o = new Fl_Box(10, 645, 70, 15, "Camera");
          o->labelsize(12);
          o->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
        }
        { Fl_Button* o = m_pbtSetCamKeyFrame = new Fl_Button(10, 660, 135, 20, "&Set");
          o->labelsize(12);
          o->user_data((void*)(this));
        }
        { Fl_Button* o = m_pbtRemoveCamKeyFrame = new Fl_Button(10, 690, 135, 20, "&Remove");
          o->labelsize(12);
          o->user_data((void*)(this));
          o->deactivate();
        }
        { Fl_Button* o = m_pbtRemoveAllCamKeyFrames = new Fl_Button(10, 720, 135, 20, "R&emove All");
          o->labelsize(12);
          o->user_data((void*)(this));
        }
        o->end();
      }
      o->end();
    }
    { Fl_Box* o = new Fl_Box(5, 30, 145, 25, "Model Controls");
      o->color(7);
      o->labelfont(1);
      o->labelsize(18);
      o->labelcolor(7);
    }
    { Fl_Group* o = new Fl_Group(5, 545, 145, 95, "Particle System");
      o->box(FL_UP_BOX);
      o->labelsize(12);
      o->user_data((void*)(this));
      o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
      { Fl_Button* o = m_pbtClearSim = new Fl_Button(10, 565, 135, 20, "C&lea Sim.");
        o->labelsize(12);
        o->user_data((void*)(this));
      }
      o->end();
    }
    o->end();
  }
  { Fl_Window* o = m_pwndModelerWnd = new Fl_Window(484, 449, "Model");
    w = o;
    o->user_data((void*)(this));
    o->when(FL_WHEN_NEVER);
    { ModelerView* o = m_pwndModelerView = new ModelerView(0, 0, 340, 295, "ModelerView");
      Fl_Group::current()->resizable(o);
    }
    o->end();
  }
}
