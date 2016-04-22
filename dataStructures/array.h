#ifndef __ARRAY_H__
#define __ARRAY_H__

template <class T>

class Array {
private:
	T *ary;
	int size;
	int max;

	void extend() {
		max+=size*.3+10;
		T* tmp=new T[max];
		for(int i=0;i<size;i++)
			tmp[i]=ary[i];
		delete[] ary;
		ary=tmp;
	}
public:
	Array() {
		size=0;
		max=10;
		ary=new T[max];
	}

	Array(int siz) {
		size=0;
		max=siz+1;
		ary=new T[max];
	}

	~Array() {
		delete[] ary;
	}

	void add(T val) {
		ary[size]=val;
		size++;
		if(size==max) {
			extend();
		}
	}

	int getSize() {
		return size;
	}

	void clear() {
		while(size)
			removeLast();
	}

	T removeLast() {
		size--;
		T last=ary[size];
		return last;
	}

	T remove(int ind) {
		T replaced=ary[ind];
		size--;
		for(int i=ind;i<size;i++)
			replace(i,ary[i+1]);
		return replaced;
	}

	T removeEff(int ind) { // TODO :: TEST
		T replaced=ary[ind];
		size--;
		ary[ind]=ary[size];
		return replaced;
	}

	int indexOf(T val) {
		for(int i=0;i<size;i++)
			if(ary[i]==val)
				return i;
		return -1;
	}

	void remove(T val) {
		int ind=indexOf(val);
		if(ind!=-1)
			remove(ind);
	}

	void removeEff(T val) {
		int ind=indexOf(val);
		if(ind!=-1)
			removeEff(ind);
	}

	T replace(int ind,T newVal) {
		T replaced=ary[ind];
		ary[ind] = newVal;
		return replaced;
	}

	T get(int ind) {
		return ary[ind];
	}

	bool contains(T val) {
		for(int i=0;i<size;i++)
			if(ary[i]==val)
				return true;
		return false;
	}
};

#endif
