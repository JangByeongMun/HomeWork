#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }

    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        DataType* tmpData = new DataType[_Size];
        for (int i = 0; i < _Size; i++)
        {
            if (i < Size_)
            {
                tmpData[i] = ArrData_[i];
            }
            else
            {
                tmpData[i] = 0;
            }
        }

        Release();
        ArrData_ = tmpData;
        Size_ = _Size;
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    // GameArray NewArray2 = GameArray(5);
    GameArray NewArray2 = GameArray(20);

    int Size = sizeof(GameArray);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    NewArray.AllValueSetting(0);
    NewArray2 = NewArray;

    // NewArray2.ReSize(20);

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }
}
