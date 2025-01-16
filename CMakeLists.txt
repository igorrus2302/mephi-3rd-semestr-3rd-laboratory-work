cmake_minimum_required(VERSION 3.29)
project(3semestr_3laboratory)

set(CMAKE_CXX_STANDARD 20)

add_executable(3semestr_3laboratory main.cpp
        person.h
        room.h
        room_allocator.cpp
        room_allocator.h
        dynamic_array.h
        sequence.h
        idictionary.h
        unique_pointer.h
        hash_table.h
        names.h
        item.h
        state_of_backpack.h
        file_generator.cpp
        file_generator.h
        file_reader.cpp
        file_reader.h
        backpack_solution.cpp
        backpack_solution.h
        menu.cpp
        menu.h
        person.cpp
        index_alphabet.cpp
        index_alphabet.h
        file_writer.cpp
        file_writer.h
        container_for_unique_pointer.h
        functional_tests.cpp
        functional_tests.h)
