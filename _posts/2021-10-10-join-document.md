---
layout: post
title:  "JOIN DOCUMENT"
date:   2021-10-10 11:12:59 +0700
author: "Akhmal R"
categories: english documentation
---

# Documentation of JOIN

## Foreword

This document made to fulfill information providing act for the platform itself (JOIN) as a general topic or for its developer, to be exact, the objectives of this document are.
- Place to log everything up about platform's development, in order to track every changes made.
- Implementing good (hopefully) software quality assurance.
- Information source for the developers.

Before aligning to the document, JOIN is platform designed as communication infrastructure for those who had a project whom needs worker or workers who need project to work. Supposedly with JOIN, project owner can get desired project worker also the workers can get desired project to work on.

## Documentation Table of Contents

1. Development Flow
2. Overall description
3. Implementation
4. Testing

## Development Flow

![directory](/images/DiagramAlirTABlack.png)<br/>
<sub>Figure 1: Development flow of JOIN</sub>

### System designing and defining

In this step of development, system defined and designed from nothing to conceptual thing. Analytical study conducted based on the objective of the system given us use case of the system then use case can be broken down to more specific concept. all conceptual matter of the system depicted as UML diagram.

### Implementation preparation

After conceptual of the system depicted, we can go to figuring out the prototype of the system. Before going to implement the system, prototyping is required in search of implementation guideline for the real system buildup.

### System implementation

We had our prototype here, so we can start to build actual system, front-end, back-end, everything. Front-end development had user interface prototype as a guideline, back-end used data requirement and data schema as a guideline, then two of it integrated.

### Documentation

Documentation is all about taking records out of the whole process of development, in order to provide information to fellow developer or system actual user. Documentation can be commited anytime in the process below as long as it can provide important information to other.

## Overall description

![directory](/images/UseCaseDiagramTABlack.png)<br/>
<sub>Figure 2: Use Case of JOIN</sub>

System can provide 4 uses for one actor, each uses can be broken down into parts but first let us show you the description.

### Manage Projects

| Name: Manage Projects |
| Primary Actor: User  |
| Interest: Project owner managing owned project |
| Short description: Add new project, edit project detail, delete or read existing projects. |
| Relationships: Association |
| Normal Flow of Event:<br/>1. See existing projects<br/>2. Managing existing projects with delete and update operations. |
| Subflow:<br/>If no project owned:<br/>1. Add new project<br/>2. Fill in data for project addition |
| Alternate/Exceptional Flow |

### Search for Projects

| Name: Search for Projects |
| Primary Actor: User  |
| Interest: Searching for desired projects to join |
| Short description: Inputting keyword for desired projects, set up search filter, send join requests. |
| Relationships: Association |
| Normal Flow of Event:<br/>1. Search with keyword<br/>If worked, to the next step<br/>If not, to  subflow 1<br/>2. See project detail<br/>3. Communicate to project owner<br/>4. Send join request |
| Subflow:<br/>If search with keyword not worked:<br/>1. Search with search filter |
| Alternate/Exceptional Flow |

### Manage Profile

| Name: Manage Profile |
| Primary Actor: User  |
| Interest: Managing own profile |
| Short description: Add profile detail, edit or delete profile detail. |
| Relationships: Association |
| Normal Flow of Event:<br/>1. See profile<br/>2. Managing profile with delete and edit operation. |
| Subflow: |
| Alternate/Exceptional Flow |

### Report Abusive

| Name: Report Abusive |
| Primary Actor: User  |
| Interest: Send a report of inapproppriate project or profile to administrator |
| Short description: Make a report of inapproppriate project or profile |
| Relationships: Association |
| Normal Flow of Event:<br/>1. See project detail<br/>2. Report project or owning profile |
| Subflow: |
| Alternate/Exceptional Flow |

## Closure

It needs time to rebuild the old project, restructured version of JOIN are being buttoned so maybe this page can be updated overtime.
