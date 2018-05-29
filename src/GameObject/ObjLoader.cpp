#include "ObjLoader.h"



ObjLoader::ObjLoader()
{
}


ObjLoader::~ObjLoader()
{
}

renderData ObjLoader::parse(const char * filepath)
{
	renderData data;
	cout << "lecture" << endl;
	ifstream stream(filepath);
	string line;
	vector<float> vertice = vector<float>();
	vector<float> textemp = vector<float>();
	vector<float> textcoord = vector<float>();
	vector<unsigned int> index = vector<unsigned int>();
	unsigned int verticeCount = 0;
	unsigned int indexCount = 0;
	unsigned int texCount = 0;
	vector<string> temp;
	vector<string> temp2;
	while (getline(stream, line))
	{
		if (line.find("vt"))
		{
			int s = splitString(temp, line, ' ');
			for (int i(1); i < s; i++)
			{
				textemp.push_back(stof(temp[i]));
			}
		}
		else if (line[0] == 'v')
		{
			int s = splitString(temp, line, ' ');
			for (int i(1); i < s; i++)
			{
				vertice.push_back(stof(temp[i]));
				verticeCount += 1;
			}
		}
		else if (line[0] == 'f')
		{
			int s = splitString(temp, line, ' ');
			for (int i(1); i < s; i++)
			{
				splitString(temp2, temp[i], '/');
				index.push_back(stoi(temp2[0]));
				indexCount++;
				textcoord.push_back(textemp[stoi(temp2[1])]);
				texCount++;
			}
		}
	}
	data.vertice = vertice;
	data.index   = index;
	data.texCoord = textcoord;
	data.verticeCount = verticeCount;
	data.indexCount = indexCount;
	data.texCount = texCount;
	return data;
}

int ObjLoader::splitString(vector<string>& vecteur, string chaine, char separateur)
{
	vecteur.clear();
	int s = chaine.size();
	string temp;
	for (int i(0); i < s; i++)
	{
		if (chaine[i] == separateur)
		{
			if (!temp.empty())
				vecteur.push_back(temp);
			temp.clear();
		}else
		{
			temp += chaine[i];
		}
	}
	vecteur.push_back(temp);
	return vecteur.size();
}
