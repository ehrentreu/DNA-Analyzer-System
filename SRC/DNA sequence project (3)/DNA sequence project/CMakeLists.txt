cmake_minimum_required(VERSION 3.15)
project(DNA_sequence_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(controller)
include_directories(controller/control_commands)
include_directories(controller/sequence_analysis)
include_directories(controller/sequence_creation)
include_directories(controller/sequence_management)
include_directories(controller/sequence_manipulation)
include_directories(model)
include_directories(view)

add_executable(DNA_sequence_project
        controller/control_commands/help.h
        controller/control_commands/list.h
        controller/control_commands/quit.h
        controller/control_commands/show.h
        controller/sequence_analysis/count.h
        controller/sequence_analysis/find.h
        controller/sequence_analysis/findall.h
        controller/sequence_analysis/len.h
        controller/sequence_creation/dup.h
        controller/sequence_creation/load.h
        controller/sequence_creation/new.h
        controller/sequence_management/del.h
        controller/sequence_management/reenum.h
        controller/sequence_management/rename.h
        controller/sequence_management/save.h
        controller/sequence_manipulation/concat.h
        controller/sequence_manipulation/pair.h
        controller/sequence_manipulation/replace.h
        controller/sequence_manipulation/slice.h
        controller/ICommand.h
        model/dna_sequence.cpp
        model/dna_sequence.h
        model/DnaCollection.h
        model/dnaRecord.h
        model/fileReader.h
        model/fileWriter.h
        model/nucleotide.h
        view/CLI.h
        view/parser.cpp
        view/parser.h
        main.cpp
        test_dna_sequence.cpp)
