#pragma once

class NewEtDep {
public:
	NewEtDep();
	NewEtDep(const NewEtDep& p_aDeplacer);
	NewEtDep(NewEtDep&& p_aDeplacer);

	NewEtDep& operator=(NewEtDep&& p_aDeplacer);

	~NewEtDep();
private:
	int* m_donnee;
};
