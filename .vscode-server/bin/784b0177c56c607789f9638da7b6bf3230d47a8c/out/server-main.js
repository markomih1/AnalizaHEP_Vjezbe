const perf=require("./vs/base/common/performance"),performance=require("perf_hooks").performance,product=require("../product.json"),readline=require("readline"),http=require("http");perf.mark("code/server/start"),global.vscodeServerStartTime=performance.now();async function start(){const e=require("minimist")(process.argv.slice(2),{boolean:["start-server","list-extensions","print-ip-address","help","version","accept-server-license-terms"],string:["install-extension","install-builtin-extension","uninstall-extension","locate-extension","socket-path","host","port","pick-port","compatibility"],alias:{help:"h",version:"v"}});["host","port","accept-server-license-terms"].forEach(t=>{if(!e[t]){const c=process.env[`VSCODE_SERVER_${t.toUpperCase().replace("-","_")}`];c&&(e[t]=c)}});const s=["list-extensions","locate-extension"],i=["install-extension","install-builtin-extension","uninstall-extension"];if(e.help||e.version||s.some(t=>!!e[t])||i.some(t=>!!e[t])&&!e["start-server"]){loadCode().then(t=>{t.spawnCli()});return}e.compatibility==="1.63"&&(console.warn(`server.sh is being replaced by 'bin/${product.serverApplicationName}'. Please migrate to the new command and adopt the following new default behaviors:`),console.warn("* connection token is mandatory unless --without-connection-token is used"),console.warn("* host defaults to `localhost`"));const o=null;let l=null;const d=()=>(l||(l=loadCode().then(t=>t.createServer(a))),l),E=require("http"),w=require("os");if(Array.isArray(product.serverLicense)&&product.serverLicense.length&&(console.log(product.serverLicense.join(`
`)),product.serverLicensePrompt&&e["accept-server-license-terms"]!==!0)){hasStdinWithoutTty()&&(console.log("To accept the license terms, start the server with --accept-server-license-terms"),process.exit(1));try{await prompt(product.serverLicensePrompt)||process.exit(1)}catch(t){console.log(t),process.exit(1)}}let m=!0,h=!0,a=null;const p=E.createServer(async(t,c)=>(m&&(m=!1,perf.mark("code/server/firstRequest")),(await d()).handleRequest(t,c)));p.on("upgrade",async(t,c)=>(h&&(h=!1,perf.mark("code/server/firstWebSocket")),(await d()).handleUpgrade(t,c))),p.on("error",async t=>(await d()).handleServerError(t));const v=sanitizeStringArg(e.host)||(e.compatibility!=="1.63"?"localhost":void 0),g=e["socket-path"]?{path:sanitizeStringArg(e["socket-path"])}:{host:v,port:await parsePort(v,sanitizeStringArg(e.port),sanitizeStringArg(e["pick-port"]))};p.listen(g,async()=>{let t=Array.isArray(product.serverGreeting)&&product.serverGreeting.length?`

${product.serverGreeting.join(`
`)}

`:"";if(typeof g.port=="number"&&e["print-ip-address"]){const c=w.networkInterfaces();Object.keys(c).forEach(function(u){c[u].forEach(function(f){!f.internal&&f.family==="IPv4"&&(t+=`IP Address: ${f.address}
`)})})}if(a=p.address(),a===null)throw new Error("Unexpected server address");t+=`Server bound to ${typeof a=="string"?a:`${a.address}:${a.port} (${a.family})`}
`,t+=`Extension host agent listening on ${typeof a=="string"?a:a.port}
`,console.log(t),perf.mark("code/server/started"),global.vscodeServerListenTime=performance.now(),await d()}),process.on("exit",()=>{p.close(),o&&o.dispose()})}function sanitizeStringArg(n){return Array.isArray(n)&&(n=n.pop()),typeof n=="string"?n:void 0}async function parsePort(n,e,s){let i;if(e){let r;if(e.match(/^\d+$/)){if(i=parseInt(e,10),i===0||!s)return i}else if(r=parseRange(e)){const o=await findFreePort(n,r.start,r.end);if(o!==void 0)return o;console.warn(`--port: Could not find free port in range: ${r.start} - ${r.end} (inclusive).`),process.exit(1)}else console.warn(`--port "${e}" is not a valid number or range. Ranges must be in the form 'from-to' with 'from' an integer larger than 0 and not larger than 'end'.`),process.exit(1)}if(s){const r=parseRange(s);if(r){if(r.start<=i&&i<=r.end)return i;{const o=await findFreePort(n,r.start,r.end);if(o!==void 0)return o;console.log(`--pick-port: Could not find free port in range: ${r.start} - ${r.end}.`),process.exit(1)}}else console.log(`--pick-port "${s}" is not a valid range. Ranges must be in the form 'from-to' with 'from' an integer larger than 0 and not larger than 'end'.`),process.exit(1)}return 8e3}function parseRange(n){const e=n.match(/^(\d+)-(\d+)$/);if(e){const s=parseInt(e[1],10),i=parseInt(e[2],10);if(s>0&&s<=i&&i<=65535)return{start:s,end:i}}}async function findFreePort(n,e,s){const i=r=>new Promise(o=>{const l=http.createServer();l.listen(r,n,()=>{l.close(),o(!0)}).on("error",()=>{o(!1)})});for(let r=e;r<=s;r++)if(await i(r))return r}function loadCode(){return new Promise((n,e)=>{const s=require("path");delete process.env.ELECTRON_RUN_AS_NODE,process.env.VSCODE_HANDLES_SIGPIPE="true",process.env.VSCODE_DEV?(process.env.VSCODE_INJECT_NODE_MODULE_LOOKUP_PATH=process.env.VSCODE_INJECT_NODE_MODULE_LOOKUP_PATH||s.join(__dirname,"..","remote","node_modules"),require("./bootstrap-node").injectNodeModuleLookupPath(process.env.VSCODE_INJECT_NODE_MODULE_LOOKUP_PATH)):delete process.env.VSCODE_INJECT_NODE_MODULE_LOOKUP_PATH,require("./bootstrap-amd").load("vs/server/node/server.main",n,e)})}function hasStdinWithoutTty(){try{return!process.stdin.isTTY}catch{}return!1}function prompt(n){const e=readline.createInterface({input:process.stdin,output:process.stdout});return new Promise((s,i)=>{e.question(n+" ",async function(r){e.close();const o=r.toString().trim().toLowerCase();o===""||o==="y"||o==="yes"?s(!0):o==="n"||o==="no"?s(!1):(process.stdout.write(`
Invalid Response. Answer either yes (y, yes) or no (n, no)
`),s(await prompt(n)))})})}start();

//# sourceMappingURL=https://ticino.blob.core.windows.net/sourcemaps/784b0177c56c607789f9638da7b6bf3230d47a8c/core/server-main.js.map
