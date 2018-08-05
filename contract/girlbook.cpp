#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;
using namespace std;

typedef struct _Feature{
    uint64_t id;
    uint64_t account_name;
    string hairColor;
    string eyeColor;
    string skinColor;
    string noise;
    string figure;
    uint64_t price;
    string pa_noise;
    string mo_noise;
    uint64_t state;
}Feature;

class girlbook: public eosio::contract{
    // @abi table data i64
    struct address {
        uint64_t id;
        uint64_t account_name;
        string hairColor;
        string eyeColor;
        string skinColor;
        string noise;
        string figure;
        uint64_t price;
        string pa_noise;
        string mo_noise;
        uint64_t state;

        uint64_t primary_key() const { return id; }
        uint64_t get_index() const {return account_name;}
        EOSLIB_SERIALIZE(address, (id)(account_name)(hairColor)(eyeColor)(skinColor)(noise)(figure)(price)(pa_noise)(mo_noise)(state))
    };
public:
    girlbook(account_name self) :contract(self) {}
    typedef eosio::multi_index< N(address), address, indexed_by<N(account_name), const_mem_fun<address, uint64_t, &address::get_index>>> address_index;

    // @abi action
	uint64_t insert(Feature features){
		address_index addresses(_self, _self);
		addresses.emplace(_self, [&](auto& address) {
		    address.id = features.account_name + features.price;
    		address.account_name = features.account_name;
    		address.hairColor = features.hairColor;
    		address.eyeColor = features.eyeColor;
    		address.skinColor = features.skinColor;
    		address.noise = features.noise;
    		address.figure = features.figure;
    		address.price = features.price;
    		address.pa_noise = features.pa_noise;
    		address.mo_noise = features.mo_noise;
    		address.state = features.state;
        });
        return features.account_name + features.price;
    }

    Feature findid(uint64_t _id){
        address_index addresses(_self, _self); // code, scope
        Feature feature = {};
        
        auto itr = addresses.find(N(_id));
        if(itr != addresses.end()){
            feature.id = _id;
            feature.account_name = itr->account_name;
            feature.hairColor = itr->hairColor;
            feature.eyeColor = itr->eyeColor;
            feature.skinColor = itr->skinColor;
            feature.noise = itr->noise;
            feature.figure = itr->figure;
            feature.price = itr->price;
            feature.pa_noise = itr->pa_noise;
            feature.mo_noise = itr->mo_noise;
            feature.state = itr->state;
        }
        return feature;
    }

    vector<Feature> findaccount(uint64_t account_name){
        address_index addresses(_self, _self); // code, scope
        Feature feature = {};
        vector<Feature> vec;
    
        auto account_index = addresses.get_index<N(account_name)>();
        auto itr = account_index.find(N(account_name));
        for(; itr != account_index.end() && itr->account_name == account_name; itr++){
            feature.id = itr->id;
            feature.account_name = itr->account_name;
            feature.hairColor = itr->hairColor;
            feature.eyeColor = itr->eyeColor;
            feature.skinColor = itr->skinColor;
            feature.noise = itr->noise;
            feature.figure = itr->figure;
            feature.price = itr->price;
            feature.pa_noise = itr->pa_noise;
            feature.mo_noise = itr->mo_noise;
            feature.state = itr->state;
            vec.push_back(feature);
        }
        return vec;
    }

};

EOSIO_ABI(girlbook, (insert)(findid)(findaccount))
