#ifndef __REMOVE_HPP__
#define __REMOVE_HPP__

class Remove {
    public:
        virtual void remove(int) = 0;
};

class RemoveList: public Remove {
    void remove(int);
};

class RemoveTask: public Remove {
    void remove(int);
};

#endif //__REMOVE_HPP__

