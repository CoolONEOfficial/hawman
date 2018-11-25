#include "bintree.h"
#include "bintreeend.h"
#include "bintreenode.h"
#include "bitfile.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

//class CharCount {
//public:
//    CharCount(BinTreeEnd& end) {
//        this->end = end;
//    }

//    BinTreeNode end;

//    BinTreeEnd* getEnd() {
//        return dynamic_cast<BinTreeEnd*>(&end);
//    }

//    bool checked = false;
//};

static set<uchar> checkedChars;

map<uchar, size_t>::iterator min_element(map<uchar, size_t> & charCounts) {
    auto min = charCounts.begin();

    auto mPairIter = charCounts.begin();
    for(; mPairIter != charCounts.end(); mPairIter++) {
        auto mPair = (*mPairIter);

        if(find() && // todo: Find
                mPair.first < (*min).first) {
            min = mPairIter;
        }
    }

    checkedChars.insert((*min).first);

    return min;
}

BinTree makeTree(map<uchar, size_t> charCounts) {
    vector<uchar> checkedChars;
    while(true) {
        auto minOne = charCounts.end(),
                minTwo = charCounts.end();

//        find_if(charCounts.begin(), charCounts.end(),
//            [&checkedCounters](const BinTreeNode& node) {

//                return true;
//            });

        minOne = min_element(charCounts);
        minTwo = min_element(charCounts);

//        auto a = (*minOne).first,aa = (*minTwo).first;
//        int d = 4;
//        for(size_t mCharCountId = 0; mCharCountId < charCounts.size(); mCharCountId++) {
//            auto mCharCount = charCounts.at(mCharCountId);
//            if(find(begin(checkedCounters), end(checkedCounters), mCharCount) == end(checkedCounters) && mCharCount.end.count < minOne.end.count) {
//                minOne = charCounts.at(mCharCountId);
//                mCharCount.checked = true;
//            }
//        }

//        for(size_t mCharCountId = 0; mCharCountId < charCounts.size(); mCharCountId++) {
//            auto mCharCount = charCounts.at(mCharCountId);
//            if(!mCharCount.checked && mCharCount.end.count < minTwo.end.count) {
//                minTwo = mCharCount;
//                mCharCount.checked = true;
//            }
//        }

//        CharCount mergeMin(
//                        BinTreeNode(minOne.getEnd(), &minTwo.end, minOne.end.count + minTwo.end.count)
//                    );
    }
}

//BinTreeNode makeTree(vector<pair<BinTreeEnd, uint>> charCountPairs) {
//    vector<CharCount> charCounts;
//    for(auto& mCount: charCountPairs)
//        charCounts.push_back(CharCount(static_cast<BinTreeNode>(mCount.first), 0));
//    return makeTree(charCounts);
//}

int main() {

//    BitFile outfile("testfile");
//    outfile.addBitVec(
//        {
//            true, false, true, false, true, false, true, false,
//            false, true, false, true, false, true, false, true,
//            true
//        }
//    );

//    outfile.flush();

    QFile infile("readable");
    if (infile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "File readable" << endl;

        vector<uchar> chars;
        while (!infile.atEnd()) {
            char ch;
            infile.getChar(&ch);
            chars.push_back(ch);
        }

        cout << "Chars: " << endl;
        for(auto m: chars) {
            cout << m << endl;
        }

        sort(chars.begin(), chars.end());

        map<uchar, size_t> charCounts;
        for(auto mCharId: chars) {
            if(charCounts.find(mCharId) == charCounts.end()) {
                charCounts.insert(pair<uchar, size_t>(mCharId, 0));
            }
            charCounts.at(mCharId)++;
        }

        BinTree tree = makeTree(charCounts);;

//        vector<BinTreeNode> charCounts;
//        for(auto mCharId: chars) {
//            auto found = find_if(charCounts.begin(), charCounts.end(), [&mCharId](pair<BinTreeEnd, uint> a)->bool{
//                return a.first.ch == mCharId;
//            });
//            if(found != charCounts.end()) {
//                (*found).second++;
//            } else {
//                charCounts.push_back(
//                            make_pair<BinTreeEnd, uint>(
//                                BinTreeEnd(), 1)
//                            );
//            }
//        }

//        cout << "charCounts: " << endl;
//        for(int mKey = 0; mKey < 256 / 4; mKey++) {
//            cout << (int) charCounts[              mKey].first.ch << '\t' << charCounts[              mKey].second << '\t' << " | "
//                 << (int) charCounts[256 / 4     + mKey].first.ch << '\t' << charCounts[256 / 4     + mKey].second << '\t' << " | "
//                 << (int) charCounts[256 / 4 * 2 + mKey].first.ch << '\t' << charCounts[256 / 4 * 2 + mKey].second << '\t' << " | "
//                 << (int) charCounts[256 / 4 * 3 + mKey].first.ch << '\t' << charCounts[256 / 4 * 3 + mKey].second << endl;
//        }

//        sort(charCounts.begin(), charCounts.end(),
//            [](pair<BinTreeEnd, int> a, pair<BinTreeEnd, int> b) {
//                return a.second > b.second;
//            }
//        );

//        cout << "Sorted charCounts: " << endl;
//        for(int mKey = 0; mKey < 256 / 4; mKey++) {
//            cout <<               mKey << '\t' << (int) charCounts[              mKey].first.ch << '\t' << charCounts[              mKey].second << '\t' << " | "
//                 << 256 / 4     + mKey << '\t' << (int) charCounts[256 / 4     + mKey].first.ch << '\t' << charCounts[256 / 4     + mKey].second << '\t' << " | "
//                 << 256 / 4 * 2 + mKey << '\t' << (int) charCounts[256 / 4 * 2 + mKey].first.ch << '\t' << charCounts[256 / 4 * 2 + mKey].second << '\t' << " | "
//                 << 256 / 4 * 3 + mKey << '\t' << (int) charCounts[256 / 4 * 3 + mKey].first.ch << '\t' << charCounts[256 / 4 * 3 + mKey].second << endl;
//        }
    } else cout << "File not readable!" << endl;
}
