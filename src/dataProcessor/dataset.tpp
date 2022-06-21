template <typename T>
Dataset<T>::Dataset(std::string *path, std::string* startMessage){
    static_assert(std::is_base_of<ICSVMember, T>::value, "type parameter of this class must derive from BaseClass");
    file = new FileWithData(path, startMessage);
    this->load();
}

template <typename T>
Dataset<T>::~Dataset(){
    std::cout << 123;
    this->save();
}

template <typename T>
void Dataset<T>::add(T* newModel){
    members.push_back(newModel);
}

template <typename T>
void Dataset<T>::remove(int index){
    if (index < members.size()){
        members.erase(members.begin()+index);
    }
}

template <typename T>
T* Dataset<T>::find(T *example){
    auto ptr = members.begin();
    while(ptr != members.end()){
        if (**ptr == *example){
            return *ptr;
        }
        ptr++;
    }

    return nullptr;
}

template <typename T>
void Dataset<T>::load(){
    while(file->hasNext()){
        T* nextMember = new T();
        file->getNextMember(nextMember);
        if (nextMember->isExist()){
            this->add(nextMember);
        }
    }
}

template <typename T>
void Dataset<T>::save(){
    file->saveData(reinterpret_cast<ICSVMember **>(&members[0]), members.size());
}

template <typename T>
std::vector<T*> Dataset<T>::getData(){
    return members;
}

template <typename T>
void Dataset<T>::sort(bool (*pt2Func)(T,T)){
    if (members.size() < 2){
        return;
    }

    T *temp;
    auto slowPtr = members.begin();
    auto fastPtr = members.begin();
    while(slowPtr != members.end()){
        fastPtr = members.begin();
        while(fastPtr != members.end()){
            if ((*pt2Func)(**slowPtr, **fastPtr)){
                temp = *slowPtr;
                *slowPtr = *fastPtr;
                *fastPtr = temp;
            }
            fastPtr++;
        }
        slowPtr++;
    }
}
