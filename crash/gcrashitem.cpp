#include "gcrashitem.h"

GCrashItem::GCrashItem()
{
    this->left=NULL;
    this->right=NULL;
}

GCrashItem::GCrashItem(GMover *left, GMover *right){
    this->left=left;
    this->right=right;
}
