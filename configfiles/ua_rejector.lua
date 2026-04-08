
if type(ngx.var.http_user_agent) == "string" then
  local blacklist = { "Go-http-client/", "Curl/", "Scrapy/", "ApacheBench/", "Apache-HttpClient/", "PycURL/", "python-requests/", "okhttp/", "OS-Scrapy/" }

  for _, ua in ipairs(blacklist) do
    if (string.find(string.lower(ngx.var.http_user_agent), ua, 1, true) ~= nil) then
      ngx.exit(ngx.HTTP_FORBIDDEN)
    end
  end
end
