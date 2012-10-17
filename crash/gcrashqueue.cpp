#include "gcrashqueue.h"

GCrashQueue::GCrashQueue()
{
    this->left=GVector(false);
    this->right=GVector(false);
}

void GCrashQueue::Append(GCrashItem item){
    this->left.Append(item.left);
    this->right.Append(item.right);
}

GCrashItem GCrashQueue::At(int index){
    return GCrashItem((GMover*)this->left.At(index),(GMover*)this->right.At(index));
}

int GCrashQueue::Size(){
    return this->left.Size();
}
