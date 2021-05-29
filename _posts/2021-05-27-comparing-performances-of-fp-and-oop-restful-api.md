---
layout: post
title:  "RESTFUL API PERFORMANCE COMPARISON"
date:   2021-05-27 21:12:59 +0700
author: "Akhmal R"
categories: english article
---

# Comparing performance of Functional and Object-Oriented Programming RESTFUL API

## Preface

So this is basically my final essay required for my bachelor's degree of computer science, I just wrote it down the line to this article in fact of any topic did not really pop out onto my mind right now, maybe tomorrow it will. In this article, I will compare two RESTFUL API I made each using Functional and Object-Oriented (OO) Programming paradigms, the value compared is performance per request sent until responded, that can be broken down to be metrics of execution time, memory used and throughput of the requests.

## RESTFUL API? introduce me to them!

As I said before, I made 2 RESTFUL API then compare it, API at a glance is the web service that act like the bridge between two or more isolated resource and RESTFUL API is an API that obey REST constraint. You can read about REST constraint yourself [here][fielding-rest][fielding-rest]:[https://www.ics.uci.edu/~fielding/pubs/dissertation/rest_arch_style.htm].

## OK I got it, what about them paradigms?

Yeah two paradigms I am going to compare are Functional and OO paradigm, these two of course can be identified by its unique attributes of paradigm. API built using Functional paradigm consists of several small functions, the execution of this API is basically the chain of function call. API built using OO paradigm consists of several programmatically-defined objects, the execution of this API is basically declared objects worked together as a team.

## Before we go further, is paradigm difference really matter for them performance?

I heard that question before ever started writing the essay, there's some journal refer the paradigm to be a real deal for the performance but I will show you one of them in here, the rest of the pack written on footnote. Cited from essay authored by Kim Svensson Sand and Tord Eliasson, the essay conducted similar performance comparison of program written in Functional and OO manner, then on near future they found out that OO have better performance than Functional one and for some development metrics like development time and length of code, Functional code required less time and less code than OO.

## What method did you use to conduct such comparison?

The method used was honestly similar to Kim and Tord's method, I developed the API with Create, Read, Update and Delete (CRUD) capabilities, design the simple database table, put the HTTP requests on the table and match to CRUD program principle, test the program to ensure its correctness, collect the data and analyze to extract the conclusion.
1. Design DB table.
2. Put the HTTP requests to matched CRUD principle.
3. Developed the API.
4. Unit-test the API.
5. Collect and analyze data.
6. Extract the conclusion.

In the beginning, we first defined what we going to develop, database structure are the crucial one. Database used is a simple one with just one table with 5 table attributes, the motive is database defined could be enough of a playing ground for the comparison. Some predevelopment thing we had to do are define the CRUD functionality and put the HTTP requests on its side, its important to do it in fact some CRUD functionality can be performed by specified HTTP requests.

| Kriminal |
| :----: |
| Id:int |
| Nama:string |
| Umur:unsign |
| TIndak:string |
| Status:string |

<sub>Table 1: A table from database</sub>

Since the two previous steps fulfilled, the API development it is, in this step we basically develop two API using each two drill. Meanwhile the HTTP requests used were 6 of POST, GET, PUT, DELETE, HEAD and PATCH for 10 kind of CRUD functionality that can be viewed in table 2.

| CRUD Function | HTTP Requests |
| :----: | :----: |
| Get first 5 row | GET |
| Add a new row | POST |
| Edit 'status' column on a row | PUT |
| Delete a row | DELETE |
| Get a row | GET |
| Edit 'status' column on a row | PATCH |
| Get a row's meta data | HEAD |
| Edit 'tindak' column on a row | PUT |
| Edit 'tindak' column on a row | POST |
| Edit 'tindak' column on a row | PATCH |

<sub>Table 2: CRUD function and matched HTTP requests</sub>

After the above table completed, we then prepared the development environment and start to write some code. Two APIs written in the guide of two paradigm said above, Functional and OO , but in case you don't get the main point, here I expresses two of them in comparison table 3.

| Object-oriented | Functional |
| :----: | :----: |
| Encapsulate its data with 'class declaration' | Encapsulate its data with 'data immutability' |
| Class, object and member have access to data | Data are in open-access to any function but editing privilege |
| Class encapsulates function | Function are declared globally |
| No side effect restriction | Have side effect restriction |

<sub>Table 3: Functional and object-oriented main difference</sub>

## How's the result?

I will jump to step 5 of the list and assume previous steps done perfectly under the bridge. For the note before we go further ahead, the entire process of the comparison took place in one local computer, so no internet connection or local area connection involved.

Data collection separated into 3 scenario of request sending, with one user, hundred users and five hundreds users, the users are controlled by load testing machine. The result of data collection for performance metric of execution time (microseconds) expressed in table 4 below and to ensure the comparison are good to analyze, Mann-Whitney value are generated as well to find out if the performance differences are such significant.

| Functional (mean) | Object-oriented (mean) | Mann-Whitney (p-value) |
| :----: | :----: | :----: |
| 248.1 | 251.4 | 0.41 |
| 230.7 | 226.6 | 0.44 |
| 141.5 | 138.2 | 0.248 |

<sub>Table 4: Data collection result</sub>

## Data were collected, so the conclusion?

We can see some insight from the comparison, that the comparison indeed have resulted such different value of performance metric every scenarios then the question is 'are the differences exist significant?'. The answer of said question is all explained by Mann-Whitney p-value, two values are in null hypothesis range until p-value are below 0.05, knowing that null hypothesis means they have insignificant difference in-between. Looking for the result, APIs I made had no significant difference.

## Closure

The result was concluded and its honestly had difference each, but not such significant. For responses of this article's airing, this is by-far my first english article and I honestly looking forward to write more especially in the performance comparison land. Good bye for now (Akhmal R).

## Footnote

- K. S. Sand and T. Eliasson, "A Comparison of Functional and Object-Oriented Programming Paradigms in JavaScript" 2017
- A. Rizkyanto, "Comparative Study of Functional and Object-oriented Programming Paradigms for RESTFUL API with JavaScript" 2021
