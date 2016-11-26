//
// Created by ilya on 13.11.16.
//

#ifndef WATERMARKENGINE_PARSERUTIL_H
#define WATERMARKENGINE_PARSERUTIL_H

#include <map>
#include <vector>
#include "DWTUtil.h"
#include "../lib/xml_parser/tinyxml.h"
#include "ProjectException.h"


/**
     * This function parses the given XML file into the list of objects
     *
     * @param fileURI URI for the XML file
     * @return Map of filters with key being Integer object for filter ID
     */
void get_filter_gh(TiXmlElement* el, DWTUtil::FilterGH*);
void get_filter(TiXmlElement* el, DWTUtil::Filter*);


std::map<int, DWTUtil::FilterGH> parse(const char* file){
    std::map<int,DWTUtil::FilterGH> res;
    //TODO: make normal path to config
    TiXmlDocument doc( "../filters.xml" );
    if (!doc.LoadFile())
        throw ProjectException("error while parsing" + std::string(doc.ErrorDesc()));

    TiXmlElement* list =  doc.FirstChildElement();

    DWTUtil::FilterGH filterGH;

    for (auto node = list->FirstChild(); node ; node = node->NextSibling()) {
        get_filter_gh(node->ToElement(), &filterGH);
        res.insert(std::make_pair(filterGH.getId(), filterGH));
    }

    return res;
};

void get_filter_gh(TiXmlElement* el, DWTUtil::FilterGH* filterGH){
    filterGH->setId(atoi(el->Attribute("id")));
    filterGH->setName(el->Attribute("name"));
    filterGH->setType(el->Attribute("type"));

    DWTUtil::Filter filter;
    int count = 0;
    for (auto node = el->FirstChild(); node ; node = node->NextSibling()) {
        get_filter(node->ToElement(), &filter);

        filter.setHipass((count & 1) != 1);

        if(count == 0)
        {
            filterGH->setG(filter);
        }
        else if(count == 1)
        {
            filterGH->setH(filter);
        }
        else if(count == 2)
        {
            filterGH->setGi(filter);
        }
        else if(count == 3)
        {
            filterGH->setHi(filter);
        }
        count++;
    }
}

void get_filter(TiXmlElement* el, DWTUtil::Filter* filter){
    filter->setType(el->Attribute("type"));
    filter->setStart(atoi(el->Attribute("start")));
    filter->setEnd(atoi(el->Attribute("end")));



    std::vector<DWTUtil::Pixel> vector;
    for (auto node = el->FirstChild(); node; node = node->NextSibling()){
        vector.push_back(atof(node->ToElement()->GetText()));
    }
    filter->setData(vector);
}


#endif //WATERMARKENGINE_PARSERUTIL_H
