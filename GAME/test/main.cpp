#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "loadmap.h"
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;


void ShowMap(map<unsigned int, char> &_map)
{
	
}

bool loadXML(const char* path)
{
}

// example as follow:
// root : "map"
// layer = "layer"
// layer_name = "background"
XMLElement* queryNodeByName(XMLElement* root, const string& layer, string layer_name = "")
{
	XMLElement* layerNode = root->FirstChildElement(layer.c_str());
	
	//没有名字，说明只有这一个
	if (layer_name == "")
	{
		return layerNode;
	}

	while (layerNode != NULL)
	{
		if (layerNode->Attribute("name") == layer_name)
		{
			break;
		}
		layerNode = layerNode->NextSiblingElement();
	}
	return layerNode;
}

string GetNodeStrVal(XMLDocument &doc, const string& layer, const string& layer_name, string node_val = "data")
{
	XMLElement* root = doc.RootElement();
	if (!root)
	{
		cout << "load root err" << endl;
		return "";
	}
	XMLElement* layer_node = queryNodeByName(root, layer, layer_name);
	
	if (layer_node != NULL)
	{
		XMLElement* data_node = queryNodeByName(layer_node, node_val);
		//XMLElement* data_node = node->FirstChildElement(node_val);
		string data_val = data_node->GetText();
		return data_val;
	}
	else
	{
		cout << "not find data at layer = " << layer_name << endl;
		return "";

	}
	return "";
}

int main()
{
	string path = "../resource/";
	string level_file = "map_level_1.tmx";
	string full_path = path + level_file;
	map<unsigned int, char> _map;

	XMLDocument doc;
	if (doc.LoadFile(full_path.c_str()) != 0)
	{
		cout << "load xml file failed!" << endl;
		return -1;
	}
	string bg_data = GetNodeStrVal(doc, "layer", "background");
	cout << bg_data << endl;
	return 0;
}
