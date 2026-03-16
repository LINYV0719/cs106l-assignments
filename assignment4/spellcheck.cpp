#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  std::vector<std::string::iterator> space_Iterator=find_all(source.begin(),source.end(),::isspace);
  Corpus tokens;
std::transform(
  space_Iterator.begin(),
  space_Iterator.end()-1,
  space_Iterator.begin()+1,
  std::inserter(tokens, tokens.end()),
  [&source](auto it1,auto it2){return Token(source,it1,it2);}
);
std::erase_if(tokens,[](const Token& token){return token.content.empty();});
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  auto view = source | 
  std::ranges::views::filter([&dictionary](const Token& t){return !dictionary.contains(t.content);}) |
  std::ranges::views::transform(
    [&dictionary](const Token& t){
    auto view = dictionary | std::ranges::views::filter([&t](const std::string& d){return levenshtein(t.content,d)==1;});
    std::set<std::string> suggestions(view.begin(), view.end());
    return Misspelling { t, suggestions };
    }
  ) |
  std::ranges::views::filter([](const Misspelling& m){return !m.suggestions.empty();});
  return std::set<Misspelling> (view.begin(),view.end());
  
};

/* Helper methods */

#include "utils.cpp"
