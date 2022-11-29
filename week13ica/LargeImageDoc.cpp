// The following code works on small data, but not on large data
#include <vector>
#include <map>
#include <set>
// Large document
class LargeImageDoc
{
public:
  // <int, string>: the page where the image is at and the filename to load the image
  LargeImageDoc(const std::map<int, std::string > &listImageInfo) : numTicks(0)
  , listImageInfo(listImageInfo) {
/*    for(auto it = listImageInfo.begin(); it != listImageInfo.end(); ++it)
    {
      LoadImage(it->first, it->second);
    }*/
  }
  void Show(int page)
  {
    //load image is there is an image on this page
    //
    //load image if it is the first time viewing this page
    if(listImageInfo.find(page) != listImageInfo.end() && setPageViewed.find(page) != setPageViewed.end()){
	LoadImage(page, listImageInfo[page]);
    }
    setPageViewed.insert(page);
  }
  
private:
  // don't change this function
  void LoadImage(int page, const std::string &fileNameImage)
  {
    for(int i=0; i<1000000; ++i)
    {
      ++numTicks;
    }
  }
  
  int numTicks;
  std::map<int, std::string> listImageInfo;
  std::set<int> setPageViewed;
};
