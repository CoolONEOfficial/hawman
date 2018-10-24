#include "bintreeend.h"
#include "bintreenode.h"
#include "bitfile.h"

#include <iostream>
#include <vector>

using namespace std;

struct CharCount {
public:
    CharCount(BinTreeEnd end) {
        this->end = end;
    }

    CharCount(BinTreeEnd end) {
        this
    }

    CharCount() {}

    BinTreeNode end;

    BinTreeNode getEnd() const {
        return dynamic_cast<BinTreeEnd>();
    }

    bool checked = false;
};

BinTreeNode makeTree(vector<CharCount> charCounts) {
    while(true) {
        CharCount minOne = charCounts.at(0),
                minTwo = charCounts.at(0);

        for(size_t mCharCountId = 0; mCharCountId < charCounts.size(); mCharCountId++) {
            auto mCharCount = charCounts.at(mCharCountId);
            if(!mCharCount.checked && mCharCount.end.count < minOne.end.count) {
                minOne = charCounts.at(mCharCountId);
                mCharCount.checked = true;
            }
        }

        for(size_t mCharCountId = 0; mCharCountId < charCounts.size(); mCharCountId++) {
            auto mCharCount = charCounts.at(mCharCountId);
            if(!mCharCount.checked && mCharCount.end.count < minTwo.end.count) {
                minTwo = mCharCount;
                mCharCount.checked = true;
            }
        }

        CharCount mergeMin(
                        BinTreeNode(&minOne.end, &minTwo.end, minOne.end.count + minTwo.end.count)
                    );
    }
}

BinTreeNode makeTree(vector<pair<BinTreeEnd, uint>> charCountPairs) {
    vector<CharCount> charCounts;
    for(auto& mCount: charCountPairs)
        charCounts.push_back(CharCount(static_cast<BinTreeNode>(mCount.first), 0));
    return makeTree(charCounts);
}

int main() {
    BinTreeNode tree(
                new BinTreeEnd('d', 0),
                new BinTreeNode(
                    new BinTreeEnd('s', 0),
                    new BinTreeEnd('a', 0)
                )
            );

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

        vector<pair<BinTreeEnd, uint>> charCounts;
        for(auto mCharId: chars) {
            auto found = find_if(charCounts.begin(), charCounts.end(), [&mCharId](pair<BinTreeEnd, uint> a)->bool{
                return a.first.ch == mCharId;
            });
            if(found != charCounts.end()) {
                (*found).second++;
            } else {
                charCounts.push_back(
                            make_pair<BinTreeEnd, uint>(
                                BinTreeEnd(), 1)
                            );
            }
        }


        cout << "charCounts: " << endl;
        for(int mKey = 0; mKey < 256 / 4; mKey++) {
            cout << (int) charCounts[              mKey].first.ch << '\t' << charCounts[              mKey].second << '\t' << " | "
                 << (int) charCounts[256 / 4     + mKey].first.ch << '\t' << charCounts[256 / 4     + mKey].second << '\t' << " | "
                 << (int) charCounts[256 / 4 * 2 + mKey].first.ch << '\t' << charCounts[256 / 4 * 2 + mKey].second << '\t' << " | "
                 << (int) charCounts[256 / 4 * 3 + mKey].first.ch << '\t' << charCounts[256 / 4 * 3 + mKey].second << endl;
        }

        sort(charCounts.begin(), charCounts.end(),
            [](pair<BinTreeEnd, int> a, pair<BinTreeEnd, int> b) {
                return a.second > b.second;
            }
        );

        cout << "Sorted charCounts: " << endl;
        for(int mKey = 0; mKey < 256 / 4; mKey++) {
            cout <<               mKey << '\t' << (int) charCounts[              mKey].first.ch << '\t' << charCounts[              mKey].second << '\t' << " | "
                 << 256 / 4     + mKey << '\t' << (int) charCounts[256 / 4     + mKey].first.ch << '\t' << charCounts[256 / 4     + mKey].second << '\t' << " | "
                 << 256 / 4 * 2 + mKey << '\t' << (int) charCounts[256 / 4 * 2 + mKey].first.ch << '\t' << charCounts[256 / 4 * 2 + mKey].second << '\t' << " | "
                 << 256 / 4 * 3 + mKey << '\t' << (int) charCounts[256 / 4 * 3 + mKey].first.ch << '\t' << charCounts[256 / 4 * 3 + mKey].second << endl;
        }

        BinTreeNode tree = makeTree(charCounts);
    } else cout << "File not readable!" << endl;
}
