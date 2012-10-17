#include "gcrash.h"
#include <qmath.h>

GCrash::GCrash()
{
}

bool GCrash::IsCrash(GMover *left, GMover *right){
    return LeftRight(left,right) || RightLeft(left,right) || TopBottom(left,right) || BottomTop(left,right);
}

bool GCrash::LeftRight(GMover *left, GMover *right){
    float l=(float)right->GetX()/(float)(left->GetX()+left->GetWidth());
    if(l<1.003){
        if((right->GetX()+right->GetWidth())>left->GetX()){
            if(left->GetY()<(right->GetY()+right->GetHeight()) && right->GetY()<(left->GetY()+left->GetHeight())){
                return true;
            }
        }
    }
    return false;
}

bool GCrash::RightLeft(GMover *left, GMover *right){
    float r=(float)left->GetX()/(float)(right->GetX()+right->GetWidth());
    if(r<1.003){
        if((left->GetX()+left->GetWidth())>right->GetX()){
            if(left->GetY()<(right->GetY()+right->GetHeight()) && right->GetY()<(left->GetY()+left->GetHeight())){
                return true;
            }
        }
    }
    return false;
}

bool GCrash::TopBottom(GMover *left, GMover *right){
    float t=(float)right->GetY()/(float)(left->GetY()+left->GetHeight());
    if(t<1.003){
        if((right->GetY()+right->GetHeight())>left->GetY()){
            if(left->GetX()<(right->GetX()+right->GetWidth()) && right->GetX()<(left->GetX()+left->GetWidth())){
                return true;
            }
        }
    }
    return false;
}

bool GCrash::BottomTop(GMover *left, GMover *right){
    float b=(float)left->GetY()/(float)(right->GetY()+right->GetHeight());
    if(b<1.003){
        if((left->GetY()+left->GetHeight())>right->GetY()){
            if(left->GetX()<(right->GetX()+right->GetWidth()) && right->GetX()<(left->GetX()+left->GetWidth())){
                return true;
            }
        }
    }
    return false;
}
