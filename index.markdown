---
layout: page
categories: [ocitao]
---

The ACE ORB (TAO) is an open source C++ implementation of the Object Management Group (OMG) Common Object Request Broker Architecture (CORBA) version 3.0. TAO is supported by [OCI](http://www.ociweb.com) and the source code is hosted on [GitHub]({{site.github.repository_url}}).

### Highlights of TAO

 - Second Generation ORB with many CORBA services
 - Designed for Real-time Applications
 - CORBA 3.0, IIOP 1.2 Compliant
 - C++ Bindings
 - Zero Cost Licensing
 - Wide Platform Support
 - Portable Architecture
 - Exceptional Performance
 - Highly Configurable
 - Reduced memory footprint
 - Based on the ACE Framework
 - Extensive Training available from OCI
 - Available documentation
 - Includes an easy to use cross-platform build tool: MPC
 - OCI can help you migrate from other ORBS.

{% assign releases = site.github.releases %}
{% if releases != null %}
    {% assign sorted_rel = site.github.releases | sort: "created_at" | reverse %}
    {% assign latest_rel = sorted_rel | first %}
 
### Current Release: [{{latest_rel.name}}]({{latest_rel.html_url}})
  
{{latest_rel.body}}
{% if latest_rel.assets != null %}
    {% assign assets = latest_rel.assets | sort: "name" | reverse %}
    {% for a in assets %}{% capture tn %}Open{{latest_rel.tag_name}}{% endcapture %}
        {% assign ext = a.name | remove: tn %}
        {% if ext == '.zip' %}
           {% assign note = 'Windows' %}
        {% else %}
            {% assign note = 'Linux/Solaris/MacOSX' %}
        {% endif %}
        [Download {{a.name}}]({{a.browser_download_url}}) ({{note}})
    {% endfor %}
{% endif %}
{% else %}
### Releases is null...
{% endif %}

### Vintage OCI TAO - 2.2a and older

 Older OCI TAO releases are available through the [OCI Download Portal](http://localhost:9090/ociProduct/show/3)
