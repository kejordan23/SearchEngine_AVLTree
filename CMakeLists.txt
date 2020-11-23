cmake_minimum_required(VERSION 3.17)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3" -DNDEBUG)

add_executable(FinalProject main.cpp Word.h Handler.h DSAVLTree.h DSHashTable.h WordIndex.h AuthIndex.h Query.h Indexer.h Indexer.cpp)
