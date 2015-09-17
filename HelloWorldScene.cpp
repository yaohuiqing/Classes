#include "HelloWorldScene.h"
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
USING_NS_CC;

void testPair()
{
  /*  类模板：template <class T1, class T2> struct pair
    参数：T1是第一个值的数据类型，T2是第二个值的数据类型。
    功能：pair将一对值组合成一个值，这一对值可以具有不同的数据类型（T1和T2），两个值可以分别用pair的两个公有成员first和second访问。*/
    pair<int, double> p1;  //使用默认构造函数
    pair<int, double> p2(1, 2.4);  //用给定值初始化
    pair<int, double> p3(p2);  //拷贝构造函数
    pair<int, double> p4;  //使用默认构造函数
    p4.first = 1;
    p4.second = 2.5;
    //
    cout << p4.first << ' '<< p4.second << endl;
    //利用make_pair进行fuzhi
    pair<int, double> p6;
    p6 = make_pair(1, 1.2);
}
void map_insert(map < string, string > *mapStudent, string index, string x)
{
    mapStudent->insert(map<string, string>::value_type(index, x));
}
void testmap()
{
    map < string, string > mapS;
    //insert element
    map_insert(&mapS, "192.168.0.128", "xiong");
    map_insert(&mapS, "192.168.200.3", "feng");
    map_insert(&mapS, "192.168.0.33", "xiongfeng");
    map < string, string >::iterator iter;
    cout << "We Have Third Element:" << endl;
    cout << "-----------------------------" << endl;
    //find element
    iter = mapS.find("192.168.0.33");
    if (iter != mapS.end()) {
        cout << "find the elememt" << endl;
        cout << "It is:" << iter->second << endl;
    } else {
        cout << "not find the element" << endl;
    }
    //see element
    for (iter = mapS.begin(); iter != mapS.end(); iter++ ) {
        cout << "| " << iter->first << " | " << iter->second << " |" << endl;
    }
cout << "-----------------------------" << endl;
    map_insert(&mapS, "192.168.0.33", "xf");
cout << "After We Insert One Element:" << endl;
cout << "-----------------------------" << endl;
    for (iter = mapS.begin(); iter != mapS.end(); iter++) {
        cout << "| " << iter->first << " | " << iter->second << " |" << endl;
    }
cout << "-----------------------------" << endl;
    //delete element
    iter = mapS.find("192.168.0.33");
    if (iter != mapS.end()) {
cout << "find the element:" << iter->first << endl;
cout << "delete element:" << iter->first << endl;
cout << "===============================" << endl;
        mapS.erase(iter);
    } else {
        cout << "not find the element" << endl;
    }
    for (iter = mapS.begin(); iter != mapS.end(); iter++ ) {
        cout << "| " << iter->first << " | " << iter->second << " |" << endl;
    }
    cout << "=================================" << endl;
}
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    testValue();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
   //testVector();
    //testMap();
   // testValue();
    testmap();
}

void testArray()
{
    auto array=__Array::create();
    auto str1=__String::create("str1");
    auto str2=__String::create("str2");
    array->addObject(str1);
    array->addObject(str2);
    for (int i=0; i<array->count();i++) {
        auto str=(__String*)array->objectAtIndex(i);
        log("str=%s",str->getCString());
        log("str=%s",str->_string.c_str());
    }

    auto dic=__Dictionary::create();
    dic->setObject(str1, "NAME");
    dic->objectForKey("NAME");
    
    
}

void HelloWorld::testVector()
{
    std::vector<int> a;
    for(int n=1;n<55;n++)
    {
        a.push_back(n);
    }
    for (int m=0; m<200; m++) {
        int k=arc4random()%54;
        std::swap(a.at(0),a.at(k));
    }
    for(auto sp:a)
    {
        printf("%d,",sp);
    }
    auto sp0=Sprite::create();
    sp0->setTag(0);
    Vector<Sprite*> vec0;
    vec0.pushBack(sp0);
    //使用capacity为5来创建一个 Vector<Object*>，然后往其中加入一个精灵
    auto sp1 = Sprite::create();
    sp1->setTag(1);
    //用一个容量初始化一个 vector
    Vector<Sprite*> vec1(5);
    //在一个确定的位置插入一个确定的对象
    vec1.insert(0, sp1);
    //我们也可以加入一整个 vector
    vec1.pushBack(vec0);
    for (auto sp:vec1) {
        log("sprite tag=%d",sp->getTag());
    }
    Vector<Sprite*> vec2(vec0);
    if (vec0.equals(vec2)) { //如果两个 vector 相同的话返回真
        log("pVec0 is equal to pVec2");
    }
    //判断 vector 是否为空
    if (!vec1.empty()) {
        //获取 vector 的 capacity 和 size，要注意的是 capacity 并不一定等于 size
        if (vec1.capacity()==vec1.size()) {
         log("pVec1->capacity()==pVec1->size()");
        }else
        {////收缩 vector 以便内存对应上元素的数量
         vec1.shrinkToFit();
         log("pVec1->capacity()==%zd; pVec1->size()==%zd",vec1.capacity(),vec1.size());
        }
        vec1.swap(vec1.front(),vec1.back());  //通过值交换 vector 中的两个元素
        if (vec2.contains(sp0)) {
            //返回一个布尔值，用于指示该对象是否存在于 vector 中
            log("The index of sp0 in pVec2 is %zd",vec2.getIndex(sp0));
        }
        //从 vector 中移除元素
        vec1.erase(vec1.find(sp0));
        vec1.clear(); //移除所有元素
        log("The size of pVec1 is %zd",vec1.size());
        
    }
    
    /*size是指容器当前拥有元素的个数，而capacity是指容器在必须分配新的存储空间之前可以存放的元素总数。如vector<int> ivect(10),ivect.capacity()=10，ivect.size()=0,当你向ivect中插入元素时，只要没有超过十个，那么capacity就不变，而size为你插入的元素的个数。当你插入第十个时，capacity=size=10,当再插入一个，即第十一个数据时，容器重新分配存储空间：ivect.capacity()=20,而ivect.size()=11,即容器重新分配空间的话是现有空间的2倍进行分配，以保证vector的效率。
     */
    
}
void HelloWorld::testMap()
{
//使用默认大小创建一个 Map<K, V>，然后往其中加入一个精灵
    auto sp0 = Sprite::create();
    sp0->setTag(0);
    Map<std::string, Sprite*> map0;
    std::string mapKey0 = "MAP_KEY_0";
    map0.insert(mapKey0, sp0);
    log("The size of map is %zd.",map0.size());
    //使用一个 Map 来初始化一个 Map<K, V>
    Map<std::string, Sprite*> map1(map0);
    std::string mapKey1 = "MAP_KEY_1";
    if(!map1.empty()){
        auto spTemp = (Sprite*)map1.at(mapKey0);
        log("sprite tag = %d", spTemp->getTag());
        auto sp1 = Sprite::create();
        sp1->setTag(1);
        map1.insert(mapKey1, sp1);
        //获取所有的key，存储在 std::vector 中，用于匹配对象
        std::vector<std::string> mapKeyVec;
        mapKeyVec = map1.keys();
        for(auto key : mapKeyVec)
        {
            auto spTag = map1.at(key)->getTag();
            log("The Sprite tag = %d, MAP key = %s",spTag,key.c_str());
        }
        log("%zd buckets in the Map container",map1.bucketCount());
        log("%zd element in bucket 1",map1.bucketSize(1));
        //如果map不为空的话，从中获取一个随机对象，否则返回一个空指针
        log("The random object tag = %d",map1.getRandomObject()->getTag());
        //find(const K& key) 可以用来在容器中根据 `key` 搜索一个元素
        //erase(const_iterator position) 可以用来通过指定迭代器删除一个元素
        log("Before remove sp0,size of map is %zd.",map1.size());
        map1.erase(map1.find(mapKey0));
        log("After remove sp0, size of map is %zd.",map1.size());
    }  
 
}
void HelloWorld::testValue()
{
    Value val;   // 调用默认构造函数
    if (val.isNull()) {
        log("val is null");
    }else{
    std::string str =val.getDescription();
    log("The description of val0:%s",str.c_str());
    }
    Value val1(65);        // 用一个 int 初始化
    log("The description of the integer value:%s",val1.getDescription().c_str());
    log("val1.asByte() = %d",val1.asInt());
    std::string strV = "string";
    Value val2(strV);   // 用 string 初始化
    log("The description of the string value:%s",val2.getDescription().c_str());
    //---------------------------------------------
    auto sp0 = Sprite::create();
    Vector<Ref*>* vecV = new Vector<Ref*>();
    vecV->pushBack(sp0);
    Value val3(vecV);   // 用 Vector 初始化
    log("The description of the Vector value:%s",val3.getDescription().c_str());
    delete vecV;
    //---------------------------------------------
    Map<std::string, Ref*>* mapV = new Map<std::string, Ref*>();
    mapV->insert(strV,sp0);
    Value val4(mapV);   // 用 Map 初始化
    log("The description of the Map value:%s",val4.getDescription().c_str());
    delete mapV;
    //---------------------------------------------
    Value val6(&val4);   // 用 value 初始化
    log("The description of the Value-type value:%s",val6.getDescription().c_str());
    //---------------------------------------------
    val2 = val1;   // 在两个不同指类型间赋值
    log("The description of val2:%s",val2.getDescription().c_str());
    val2 = 4;   // 直接赋值
    log("The description of val4:%s",val2.getDescription().c_str());
    
}
//发生变化了





