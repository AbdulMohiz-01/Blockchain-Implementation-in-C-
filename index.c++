#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <openssl/sha.h>

using namespace std;

string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class Block
{
public:
    string prevHash;
    string hash;
    string data;
    time_t timestamp;
    int index;

    Block(int idx, const string &data, const string &prevHash)
    {
        index = idx;
        this->data = data;
        this->prevHash = prevHash;
        timestamp = time(nullptr);
        hash = calculateHash();
    }

    string calculateHash() const
    {
        stringstream ss;
        ss << index << timestamp << data << prevHash;
        return sha256(ss.str());
    }
};

class Blockchain
{
public:
    vector<Block> chain;

    Blockchain()
    {
        chain.emplace_back(Block(0, "Genesis Block", "0"));
    }

    void addBlock(const string &data)
    {
        int index = chain.size();
        string prevHash = chain.back().hash;
        chain.emplace_back(Block(index, data, prevHash));
    }

    bool isChainValid() const
    {
        for (size_t i = 1; i < chain.size(); ++i)
        {
            const Block &currentBlock = chain[i];
            const Block &prevBlock = chain[i - 1];

            if (currentBlock.hash != currentBlock.calculateHash())
            {
                return false;
            }

            if (currentBlock.prevHash != prevBlock.hash)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Blockchain myBlockchain;

    cout << "Adding blocks to the blockchain..." << endl;
    myBlockchain.addBlock("Block 1 Data");
    myBlockchain.addBlock("Block 2 Data");

    cout << "Is blockchain valid? " << (myBlockchain.isChainValid() ? "Yes" : "No") << endl;

    for (const auto &block : myBlockchain.chain)
    {
        cout << "Index: " << block.index << endl;
        cout << "Data: " << block.data << endl;
        cout << "Timestamp: " << block.timestamp << endl;
        cout << "Hash: " << block.hash << endl;
        cout << "Previous Hash: " << block.prevHash << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
