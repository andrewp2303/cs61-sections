#include <map>
#include <cstdint>
#include <cstdio>
#include <cassert>

struct sample {
    uintptr_t start;
    size_t duration;
    size_t flapcount;
};

std::map<uintptr_t, sample> flapmap;
using flapmap_iter = std::map<uintptr_t, sample>::iterator;

void add_sample(uintptr_t start, size_t duration, size_t flapsize){
	// method 1 (traditional)
	flapmap[start] = {.start = start, .duration = duration, 
		.flapcount = flapsize};
	// replaces at map[key]

	// method 2 (c++, higher level)
	flapmap.insert({start, {start, duration, flapsize}});
	// {K,V} = {Key, {STRUCT = value}}
	// does not overwrite, instead inserts inside
}

bool has_sample (uintptr_t t){

	auto it = flapmap.lower_bound(t);

	if (it->first == t){
		return true;
	}

}