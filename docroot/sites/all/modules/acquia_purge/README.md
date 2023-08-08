[//]: # ( clear&&curl -s -F input_files[]=@PROJECTPAGE.md -F from=markdown -F to=html http://c.docverter.com/convert|tail -n+11|head -n-2 )
[//]: # ( curl -s -F input_files[]=@PROJECTPAGE.md -F from=markdown -F to=pdf http://c.docverter.com/convert>PROJECTPAGE.pdf )

**_Top-notch proactive purging on Acquia Cloud!_**

The ``acquia_purge`` module allows Drupal sites hosted on _Acquia Cloud_ to
automatically _purge_ (wipe) pages from their Varnish powered load balancers, as
soon as content actually changed. The higher Drupal's "_expiration of cached
pages_"-setting (TTL) is configured the more your site will be served directly
off your load balancers. This effectively increases the efficiency of your site
and lowers hardware costs, leaving more resources for back-end traffic. In most
scenarios the module offers a full *turn-key experience* without requiring any
technical configuration.

**Features:**

* Built with editorial people and end-users in mind.
* On-screen progressbar showing pages being cleared and made public.
* Turn-key installation for simple content sites.
* Wipes pages based on detected changes by the [expire module](http://www.drupal.org/project/expire).
* Integration with Rules allowing to wipe pages like ``news``, ``news/?page=0`` and ``contact``.
* NEW invalidate using wildcards like ``news/*``.
* Transparently wipes pages from Drupal's page cache.
* Detects your Acquia Cloud domain names allowing manual overriding.
* Support for both Domain Access and multi-site setups.
* Detailed watchdog logging on everything that happens.
* Atomic operation based on AJAX and the Queue API.
* Drush toolkit: ``ap-diagnosis``, ``ap-domains``, ``ap-forget``, ``ap-list``, ``ap-process``, ``ap-purge``.

## Why do I need this?

Throughout the years the Acquia Support department has seen thousands of Drupal
sites pass by on daily basis and one of the most typical things we have noticed
is that many sites run with a very low "_expiration of cached pages_"-setting
(e.g. 5 minutes). This means that every single page ever generated by Drupal
will be cached very shortly by your load balancer and regenerated for no reason
just a couple of minutes after that. This puts your web servers under the
constant task of generating pages regardless if they actually changed or not.

By applying _**proactive purging**_ on your site, it will actively tell your
load balancers what pages to forget while keeping the others in cache for much
longer. This hugely decreases the stress on your web servers and leaves more
"PHP processes" available for actual back-end traffic. Basically *every site*
will benefit from implementing this, especially content-focused sites like news
sites, blogs and brand sites.

## Questions and documentation

Feel free to contact me anytime regarding questions you might have, or if you
are a Acquia customer, feel free to file a ticket with our support team and
mention its about Acquia Purge.

* [**INSTALL.md**](http://cgit.drupalcode.org/acquia_purge/plain/INSTALL.md?h=7.x-1.x)
* [**DOMAINS.md**](http://cgit.drupalcode.org/acquia_purge/plain/DOMAINS.md?h=7.x-1.x)
* [**FAQ.md**](http://cgit.drupalcode.org/acquia_purge/plain/FAQ.md?h=7.x-1.x)

## Scenario specific advice
If any of the following scenarios apply to your configuration, please continue reading.

#### Your Acquia Load balancers run a customized VCL
Officially, this module **does not support** customized VCL configurations. It is hard to support these customizations because they vary widely and having various different code paths within Acquia Purge itself, is a big risks for its general use case. If you however do require one, make sure to not overload ``vcl_hash``, any of the PURGE routines within ``vcl_recv`` and ``vcl_hit``. Sites with whitelist customizations need to explicitly hardcode their webservers internal IP addresses in order to make it technically work.

#### We use Acquia's GeoIP feature
This feature is currently experimentally supported by Acquia Purge, but may still cause issues. Acquia Purge will automatically switch to using ``BAN`` requests when it detected the ``X-Geo-Country`` header generated by Acquia Cloud's GeoIP implementation. However, the module will generate a diagnostic warning indicating that this support is still experimental and if you haven't yet, you are recommended to install the ``acquia_geoip_vary_by_country`` module and go through https://docs.acquia.com/cloud/configure/geoip.

#### Single database, more than 6 domains
Acquia Purge calculates URLs for each domain your site is served on and this is resource-intensive. To prevent your Drupal site from killing itself, the module disables itself when more than 6 domains are configured. You can serve on as many domains as you want, but what we recommend is to ``.htaccess``-redirect everything onto just 1 domain name so that the amount of cached entries are kept to a minimum. This then allows you to set ``$conf['acquia_purge_domains']`` for a single domain and have both high cache efficiency and a low usage footprint on your load balancers.

#### Single database, many domains through the "Domain Access" module
This scenario is not well supported by Acquia Purge for Drupal 7 and you are strongly recommended to reconsider your configuration. Acquia Purge's technical architecture stands a clean fix to this problem in the way and there unfortunately isn't a simple fix to the problem. You can read more about it on https://www.drupal.org/node/2561185#comment-12062633 but the bottom line is that you are recommended to move to Drupal 8 for cache tags based cache invalidation or run with a short TTL without the Acquia Purge module.

#### Multiple databases, many domains through a multi-site setup
This is possible, well supported and subject to same requirements as single sites have. As documented in DOMAINS.md, you will need to setup ``sites/sites.php`` to aid Acquia Purge's domain detection and above all, test everything carefully!

#### Acquia Cloud Site Factory
Similar to the multi-site recommendation here above, make sure to either setup ``sites/sites.php`` or manually override the domains you need to clear.