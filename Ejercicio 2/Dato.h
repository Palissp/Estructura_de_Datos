#pragma once
template <typename T>
class Dato{
	
	public:
		void setDato(T n);
		T getDato()const;
		
	private:
		T dat;
};